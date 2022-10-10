import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
# ---
# Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.

# light_x: the X position of the light of power
# light_y: the Y position of the light of power
# initial_tx: Thor's starting X position
# initial_ty: Thor's starting Y position
light_x, light_y, initial_tx, initial_ty = [int(i) for i in input().split()]

# game loop
while True:
    remaining_turns = int(input())  # The remaining amount of turns Thor can move. Do not remove this line.
    
    if light_y > initial_ty and light_x > initial_tx:
        print("SE")
        initial_ty+=1
        initial_tx+=1
    elif light_y > initial_ty and light_x < initial_tx:
        print("SW")
        initial_ty+=1
        initial_tx-=1
    elif light_y < initial_ty and light_x > initial_tx:
        print("NE")
        initial_ty-=1
        initial_tx+=1
    elif light_y < initial_ty and light_x < initial_tx:
        print("NW")
        initial_ty+=1
        initial_tx-=1
    elif light_y > initial_ty:
        print("S")
        initial_ty+=1
    elif light_y < initial_ty:
        print("N")
        initial_ty-=1
    elif light_x > initial_tx:
        print("E")
        initial_tx+=1
    elif light_x < initial_tx:
        print("W")
        initial_tx-=1
        
    if light_y > initial_ty:
        print("S")
    elif light_y < initial_ty:
        print("N")
    elif light_x > initial_tx:
        print("E")
    elif light_x < initial_tx:
        print("W")


    # A single line providing the move to be made: N NE E SE S SW W or NW