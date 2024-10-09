from calcul_tools import *
from draw import *
from simu import Simulation
from boat import Boat
from buoy import Buoy



class SimulationRunner:
    def __init__(self):
        self.s = 8
        self.dt = 0.1 
        self.k = 0.5
        self.Ɛ = 2
        self.num_steps = 1000
        self.record_data = False


    def initialize_sea_objects(self):
        sea_objects = []
        sea_objects.append(Boat(222, -6, 2, 1.5, 0.25, 4, 1.75))
        sea_objects.append(Buoy(333, 0, 2, 0, 1, 0, 0))
        # sea_objects.append(Ship(444, -10, -4, 1.5, 0.15))
        return sea_objects



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



