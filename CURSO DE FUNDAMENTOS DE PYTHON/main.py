import random

options= ("piedra", "papel", "tijera")


user_option= (input ('piedra, papel o tijera => ')).lower()

if not user_option in options:
    print("Esa opcion no es valida")

computer_option = random.choice(options)

if user_option in options:
    print("User option =>",user_option)
    print("Computer option =>",computer_option)

if user_option == computer_option:
    print("Empate!")
    
elif user_option =="piedra":
    if computer_option == "tijera":
        print("Piedra gana a tijera")
        print("Usted gano!")
    else:
        print("Papel gana a piedra")
        print("Computer gano!")
        
elif user_option == "papel":
    if computer_option == "piedra":
        print("Papel gana a piedra")
        print("Usted gano!")
    else:
        print("Tijeras gana a papel")
        print("Computer gano!")

elif user_option == "tijera":
    if computer_option == "papel":
        print("Tijeras gana a papel")
        print("Usted gano!")
    else:
        print("Piedra gana a tijeras")
        print("Computer gano!")