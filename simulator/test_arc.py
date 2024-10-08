from draw import *
from math import pi 

def draw_cone_arc(pos_robot, R, alpha, cap) :
    """
    Args:
        pos_robot (array): coordinates of the robot (x,y)
        R (float): robot detection range
        alpha (deg):robot detection angle
        cap (deg): robot heading (angle)
        ici on considère comme le cap l'angle de la direction du robot en degré
    """
    alpha = np.radians(alpha)
    cap = np.radians(cap)
    # plt.xlim(-5, 13.5)
    # plt.ylim(-2.5, 16)
    axis('equal')
    draw_arrow_test_arc(pos_robot[0], pos_robot[1],cap,2,col='red',w=1)
    
    edge_1_x = pos_robot[0] + R*cos(alpha/2 +cap)
    edge_1_y = pos_robot[1] + R*sin(alpha/2 + cap)
    edge_2_x = pos_robot[0] + R*cos(-alpha/2 + cap)
    edge_2_y = pos_robot[1] + R*sin(-alpha/2 + cap)
    
    # edge_1 = array([[edge_1_x], [edge_1_y]])
    edge_2 = array([[edge_2_x], [edge_2_y]]) #extremité droite de la zone de detection
    robot = array([[pos_robot[0]], [pos_robot[1]]])

    # array à remplir pour colorier la zone de detection
    sector_points_x = [pos_robot[0], edge_1_x]
    sector_points_y = [pos_robot[1], edge_1_y]

    # On crée la liste des points le long de l'arc de cercle
    num_arc_points = 200
    arc_angles = np.linspace(cap + alpha / 2, cap - alpha / 2, num_arc_points)
    arc_x = pos_robot[0] + R * np.cos(arc_angles)
    arc_y = pos_robot[1] + R * np.sin(arc_angles)

    sector_points_x.extend(arc_x)
    sector_points_y.extend(arc_y)

    # Onr ajoute l'autre bord de zone pour completer la liste des points du secteur
    sector_points_x.append(edge_2_x)
    sector_points_y.append(edge_2_y)

    # On colorie la zone de détection

    plt.fill(sector_points_x, sector_points_y, 'cyan', alpha=0.2)
    
    plot([pos_robot[0], edge_1_x],[pos_robot[1], edge_1_y], 'bo', linestyle="-")
    plot([pos_robot[0], edge_2_x],[pos_robot[1], edge_2_y], 'bo', linestyle="-")
    plot(pos_robot[0], pos_robot[1], 'ko')
    draw_arc(robot,edge_2,alpha,col = 'red')


a = array([0, 5])
R = 10
alpha = 90
cap = 30

def range_variation_tests():

    print("Tests de la zone de détection en faisant varier R, alpha et le cap")

    for i in range(90):
        cap_mov = i
        draw_cone_arc(a, R, alpha, cap_mov)
        st = "mouvement de la zone de détection pour un cap de {} degrés".format(i)
        title(st)
        pause(0.05)
        plt.clf() 

    for i in range(14):
        R_mov = i+1
        draw_cone_arc(a, R_mov, alpha, cap)
        st = "mouvement de la zone de détection pour une distance de visibilité de {} mètres".format(R_mov)
        title(st)
        pause(0.1)
        plt.clf() 

    for i in range(139):
        alpha_mov = i+1
        draw_cone_arc(a, R, alpha_mov, cap)
        st = "mouvement de la zone de détection pour un cone de visibilité de {} degrés".format(alpha_mov)
        title(st)
        pause(0.05)
        plt.clf()

    
if __name__ == "__main__":
    draw_cone_arc(a, R, alpha, cap)
    pause(5)
    #range_variation_tests()