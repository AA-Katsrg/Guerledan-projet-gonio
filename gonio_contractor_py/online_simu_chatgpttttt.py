import codac as c1
import codac2 as c2
import math
import random
import time
from vibes import vibes
import numpy as np
import interface_codac as Interface

# 🔹 Time step and simulation parameters
dt = 0.05
iteration_dt = 0.2  # Elapsed time per step
tdomain = c1.Interval(0, 15)

# 🔹 Initial pose
x0 = (0, 0, 2)

# 🔹 Create `TubeVector` with infinite uncertainty (to be refined later)
x = c1.TubeVector(tdomain, dt, 3)
v = c1.TubeVector(tdomain, dt, 3)
u = c1.Tube(tdomain, dt)

# Set initial values to infinite uncertainty
x.set_empty()
v.set_empty()
u.set_empty()

# 🔹 Initialize contractor network
cn = c1.ContractorNetwork()
ctc_deriv = c1.CtcDeriv()
ctc_eval = c1.CtcEval()
cn.add(ctc_deriv, [x, v])  # Apply motion constraints

# 🔹 Initialize visualization
c1.beginDrawing()
fig_map = c1.VIBesFigMap("Real-Time SLAM")
fig_map.set_properties(100, 100, 500, 500)
fig_map.axis_limits(-20, 25, -10, 15)
fig_map.show(1)

# 🔹 Initialize time variables
t = tdomain.lb()
prev_t_obs = t
measurements = {}  # Store detected landmarks

while t < tdomain.ub():  # Run from t0 to tf

    # Simulate system input u (control variable)
    u_t = 3 * (math.sin(t) ** 2) + t / 100  # Example function
    u.set(c1.Interval(u_t).inflate(0.03), t)  # Set value at t

    # 🔹 Apply motion model dynamically
    v[2].set(u(t), t)  # Set angular velocity
    v[0].set(10 * c1.cos(x[2](t)), t)  # Velocity x
    v[1].set(10 * c1.sin(x[2](t)), t)  # Velocity y
    x.set(v.primitive() + c1.IntervalVector([x0[0], x0[1], x0[2]]), t)

    # 🔹 Add the current state to contractor network
    cn.add_data(x, t)
    cn.add_data(v, t)

    # 🔹 Simulate new landmark detection every 2*dt
    if t - prev_t_obs > 2 * dt:

        # Generate a new landmark observation
        mi = c1.IntervalVector([
            c1.Interval(random.randint(-10, 10)),
            c1.Interval(random.randint(-10, 10))
        ])

        # Compute bearing measurement
        x_t = x(t)  # Get estimated position at t
        angle = math.atan2(mi[1].mid() - x_t[1], mi[0].mid() - x_t[0]) - x_t[2]
        y = c1.Interval(angle).inflate(0.005)

        print(f"[{t:.1f}s] New landmark detected: {mi}, Bearing: {y}")

        # Store measurement
        if t not in measurements:
            measurements[t] = []
        measurements[t].append((mi.inflate(0.05), y))

        # 🔹 Add new observation constraints
        p = cn.create_interm_var(c1.IntervalVector(3, (-c1.oo, c1.oo)))
        M_list = [m for m, _ in measurements[t]]
        y_list = [y for _, y in measurements[t]]

        ctc_gonio = Ctc_gonio(M_list, y_list)
        cn.add(ctc_eval, [t, p, x, v])  # Constrain position at t
        cn.add(ctc_gonio, [p])  # Apply bearing constraint

        # Mark detection time
        prev_t_obs = t

        # Display detected landmark
        fig_map.add_beacon(mi, "red")

    # 🔹 Perform real-time contraction
    contraction_dt = cn.contract_during(iteration_dt)

    # 🔹 Pause for animation if necessary
    if iteration_dt > contraction_dt:
        time.sleep(iteration_dt - contraction_dt)

    # 🔹 Update visualization
    fig_map.draw_box(x(t).subvector(0, 1), "blue")

    # Move forward in time
    t += dt

fig_map.show(1)
vibes.endDrawing()
