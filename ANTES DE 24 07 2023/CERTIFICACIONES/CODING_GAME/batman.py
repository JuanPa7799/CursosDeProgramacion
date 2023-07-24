import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

# w: width of the building.
# h: height of the building.
w, h = [int(i) for i in input().split()]
n = int(input())  # maximum number of turns before game over.
x0, y0 = [int(i) for i in input().split()]
m=4
digonal_dr_ul=False
digonal_dr_ul=False
digonal_dr_ul=False
digonal_dr_ul=False

# game loop
while True:
    bomb_dir = input()  # the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)

    if bomb_dir==("UR"):
        x0+=m
        y0-=m
    elif bomb_dir==("UL"):
        x0-=m
        y0+=m
    elif bomb_dir==("DR"):
        x0+=m
        y0+=m
    elif bomb_dir==("DL"):
        x0-=m
        y0+=m
    elif bomb_dir==("U"):
        y0-=m
    elif bomb_dir==("L"):
        x0-=m
    elif bomb_dir==("D"):
        y0+=m
    elif bomb_dir==("R"):
        x0+=m


    # the location of the next window Batman should jump to.
    print(str(x0)+" "+str(y0))
