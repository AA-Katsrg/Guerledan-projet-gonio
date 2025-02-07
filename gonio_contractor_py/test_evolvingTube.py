import codac as c1

# Initial time domain and tube
dt = 0.1
tdomain = c1.Interval(0, 5)  # Start with [0,5] interval
x = c1.TubeVector(tdomain, dt, 2)  # 2D TubeVector

# Set initial values for the tube
x.set(c1.IntervalVector([c1.Interval(-1, 1), c1.Interval(3, 5)]))

print("Initial Tube Domain:", x.tdomain())
print("Initial Tube:", x)

# Simulate time evolution
for step in range(3):  # Simulating 3 updates
    new_tmax = x.tdomain().ub() + 5  # Extend the time domain by 5 units
    new_tdomain = c1.Interval(0, new_tmax)  # New extended time domain

    # Create a new, larger tube
    new_x = c1.TubeVector(new_tdomain, dt, 2)

    # Copy existing values from old tube to new tube over the previous time domain
    for i in range(x.size()):  # Iterate over dimensions
        for t in x.tdomain():  # Iterate over time slices
            new_x[i].set(x[i](t), t)  # Copy slice by slice

    # Add new uncertainty for the new time interval
    new_x.set(c1.IntervalVector([c1.Interval(-2, 2), c1.Interval(2, 4)]), c1.Interval(x.tdomain().ub(), new_tmax))

    # Replace old tube with the new one
    x = new_x

    print(f"Expanded Tube Domain at step {step+1}: {x.tdomain()}")
    print("Updated Tube:", x)
