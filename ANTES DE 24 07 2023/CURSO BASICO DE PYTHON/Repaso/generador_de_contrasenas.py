import random

def generar_contrasena():
    mayusculas = ['A', 'B', 'C', 'D', 'E', 'F', 'G']
    minusculas = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
    simbolos = ['!', '#', '$', '&', '/', '(', ')']
    numeros = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']
    caracteres= mayusculas + minusculas + simbolos + numeros;
    
    contraseña = []
    
    for i in range(15):
        caracter_random = random.choice(caracteres)
        contraseña.append(caracter_random)
        
    contraseña = "".join(contraseña)
    return contraseña
    

def run():
    contrasena= generar_contrasena()
    print('Tu nueva contrasena es: ' +contrasena)
    

if __name__=='__main__':
    run()