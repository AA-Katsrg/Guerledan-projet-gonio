from sea_object import *
from calcul_tools import *
from draw import *

class Buoy(SeaObject):

    def __init__(self, tag, x, y, v, theta, R, sight_angle):
        super().__init__(tag, x, y, v, theta, R, sight_angle)  # call the superclass's constructor
        self.privilege = 1000
        self.r = 0.3        # size of the buoy
        self.col = "blue"   # color of the buoy

    def draw(self, ax, Ɛ):
        print('tag, in_area=', self.tag, self.in_area)
        if self.in_area :
            print('green')
            draw_disk(ax, array([[self.x], [self.y]]), self.r, "green")
        else :
            draw_disk(ax, array([[self.x], [self.y]]), self.r, self.col)


    # The buoy doesn't move for now
    def move(self, record_data, boats, ax, Ɛ, s, k, dt):
        return [self.tag, self.get_state_vector()]