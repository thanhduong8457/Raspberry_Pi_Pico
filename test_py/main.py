import numpy as np
import math

dtr = math.pi / 180.0

def unit_vector(xo, yo, zo, xf, yf, zf):
    delta_x = xf - xo
    delta_y = yf - yo
    delta_z = zf - zo
    modulo = math.sqrt(((delta_x) ** 2) + ((delta_y) ** 2) + ((delta_z) ** 2))
    nx = delta_x / modulo
    ny = delta_y / modulo
    nz = delta_z / modulo
    return [nx, ny, nz]

def angulos_rot(nx, ny, nz):
    if (nz < 0):
        theta_z = (360 * dtr) + math.asin(nz)
    else:
        theta_z = math.asin(nz)

    if (nx < 0):
        theta_y = (180 * dtr) + (math.atan(ny / nx))
    elif (nx == 0):
        if (ny < 0):
            theta_y = (270 * dtr)
        elif (ny == 0):
            theta_y = 0
        else:
            theta_y = (90 * dtr)
    else:
        if (ny < 0):
            theta_y = (360 * dtr) + (math.atan(ny / nx))
        else:
            theta_y = (math.atan(ny / nx))

    return [theta_z, theta_y]


xo = 1
yo = 1
zo = 1

xf = 2
yf = 2
zf = 5

rot_z = np.zeros((3, 3))
rot_y = np.zeros((3, 3))
rot_tras = np.zeros((4, 4))

pf = np.zeros((3, 1))
pf_trans = np.zeros((4, 1))

rot_tras[0, 0] = 1
rot_tras[1, 1] = 1
rot_tras[2, 2] = 1
rot_tras[3, 3] = 1
rot_tras[0, 3] = -xo
rot_tras[1, 3] = -yo
rot_tras[2, 3] = -zo

pf_trans[0, 0] = xf
pf_trans[1, 0] = yf
pf_trans[2, 0] = zf
pf_trans[3, 0] = 1

x_trans = (rot_tras).dot(pf_trans)

NN = unit_vector(0, 0, 0, x_trans[0, 0], x_trans[1, 0], x_trans[2, 0])
angles = angulos_rot(NN[0], NN[1], NN[2])
theta_y = angles[1]
theta_z = angles[0]

cos_axisz = math.cos(theta_y)
sin_axisz = math.sin(theta_y)

cos_axisy = math.cos(theta_z)
sin_axisy = math.sin(theta_z)

  ######  Rotacion Z  ######
  # Plano xy ya trasladado
pf[0, 0] = x_trans[0, 0]
pf[1, 0] = x_trans[1, 0]
pf[2, 0] = x_trans[2, 0]
  # Rotacion respecto a eje Z
rot_z[0, 0] = cos_axisz
rot_z[0, 1] = sin_axisz
rot_z[1, 0] = -1 * sin_axisz
rot_z[1, 1] = cos_axisz
rot_z[2, 2] = 1

m_rot1 = rot_z.dot(pf)

rot_y[0, 0] = cos_axisy
rot_y[0, 2] = sin_axisy
rot_y[1, 1] = 1
rot_y[2, 0] = -sin_axisy
rot_y[2, 2] = cos_axisy

m_rot2 = rot_y.dot(m_rot1)

# print(x_trans)
# print(x_trans[0, 0])
# print(x_trans[1, 0])
# print(x_trans[2, 0])
# print("\n")
# print(NN)
# print("\n")
# print(theta_y)
# print(theta_z)
print((m_rot2[0, 0]))

print(np.sign(-4))