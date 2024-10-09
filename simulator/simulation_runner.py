from calcul_tools import *
from draw import *
from simu import Simulation
from boat import Boat
from island import Island



class SimulationRunner:
    def __init__(self):
        self.s = 15 
        self.dt = 0.1 
        self.k = 0.5
        self.Ɛ = 2
        self.num_steps = 1000
        self.record_data = False
        # self.rules = [
        #     ["Rules :"],
        #     ["Finish OT"],
        #     ["Left OT"],
        #     ["Right OT"],
        #     ["R to R"]
        # ]
        # self.legend = [
        #     ["Finish overtaking the obstacle", "Finish OT"],
        #     ["Overtaking the obstacle on the left side", "Left OT"],
        #     ["Overtaking the obstacle on the right side", "Right OT"],
        #     ["Red to red rule to avoid the collision", "R to R"]
        # ]



    def initialize_sea_objects(self):
        sea_objects = []
        sea_objects.append(Boat(222, -3, 5, 1.5, 0.25))
        sea_objects.append(Island(333, 0, 2, 0, 1))
        # sea_objects.append(Ship(444, -10, -4, 1.5, 0.15))
        return sea_objects

    # def initialize_data(self, sea_object, rules):
    #     mmsi_list = []
    #     # Create each blank cases
    #     for row in range(1, len(rules)):
    #         for col in range(len(sea_object)):
    #             rules[row].append(" ")
    #     # Create the colum's titles
    #     for col in range(len(sea_object)):
    #         rules[0].append(sea_object[col].mmsi)
    #         mmsi_list.append(sea_object[col].mmsi)
    #     return rules, mmsi_list



    def run(self):
        sea_objects = self.initialize_sea_objects()
        # rules, mmsi_list = self.initialize_data(sea_objects, self.rules)
        simulation = Simulation(sea_objects, self.dt, self.k)
        fig, ax = init_figure(-self.s, self.s, -self.s, self.s)
        # fig_leg, ax_leg = init_figure(-self.s, self.s, -self.s, self.s)
        # table = init_table(rules, self.legend, fig_leg, ax_leg)
        if self.record_data:
            simulation.run_with_data(self.record_data, self.num_steps, ax, self.Ɛ, self.s)
        else:
            simulation.run(self.record_data, self.num_steps, ax, self.Ɛ, self.s)



    # ------------------------------------------------------------------------------------------------



