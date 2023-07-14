import random

options= ("piedra", "papel", "tijera")
computer_wins = 0
user_wins = 0



rounds = 1

while True:
    print('*'*20)
    print('Round', rounds)
    print('*'*20)
    
    

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
            user_wins += 1
        else:
            print("Papel gana a piedra")
            print("Computer gano!")
            computer_wins += 1
            
    elif user_option == "papel":
        if computer_option == "piedra":
            print("Papel gana a piedra")
            print("Usted gano!")
            user_wins += 1
        else:
            print("Tijeras gana a papel")
            print("Computer gano!")
            computer_wins += 1

    elif user_option == "tijera":
        if computer_option == "papel":
            print("Tijeras gana a papel")
            print("Usted gano!")
            user_wins += 1
        else:
            print("Piedra gana a tijeras")
            print("Computer gano!")
            computer_wins += 1
    
    rounds += 1