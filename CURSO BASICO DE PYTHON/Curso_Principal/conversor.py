def conversor (tipo_pesos, valor_dolar):
    pesos = input ("¿Cuantos pesos " + tipo_pesos + " tienes?:")
    pesos = float (pesos)
    dolares = pesos / valor_dolar
    dolares = round (dolares , 2)
    dolares = str(dolares)
    print ("Tienes $"+ dolares + "dolares")   #Bloque de codigo

menu = """
Bienvenido al consversor de monedas

1 - Peso colombiano
2 - Peso argntino
3 - Peso mexicano

Elige una opción:
"""

opcion = int(input(menu))

if opcion == 1:
    conversor("colombianos", 3875 )
elif opcion == 2:
    conversor("colombianos", 65 )

    
elif opcion == 3:
    conversor("colombianos", 24 )

else:
    print("Ingresa una opcion correcta porfavor")

# dolares = input ("¿Cuantos dolares tienes?:")
# dolares = float (dolares)
# valor_dolar = 20
# peso = dolares / valor_dolar
# peso = round (dolares , 2)
# peso = str(peso)
# print ("Tienes $"+ dolares + "dolares")