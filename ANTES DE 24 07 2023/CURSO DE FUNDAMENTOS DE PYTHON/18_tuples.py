numbers = (1, 2, 3, 5)
strings = ('nico', 'zule', 'santi', 'nico')
print(numbers)
print ("0 =>",numbers[0])
print(type(numbers))
print(strings)
print(type(strings))

#LAS TUPALS PUEDEN TENER DISTINTOS TIPIOS DE DATOS

#CRUD #!NO EXISTE EN TUPLAS
#!NO SE PUEDE MODIFICAR, ES SOLO DE LECTURA UNA VEZ DECLARADA


print(strings)
print(strings.index('zule'))
print(strings.count('nico'))

my_list= list(strings)
print(my_list)
print(type(my_list))

my_list[1]= 'juli'
print(my_list)

my_tuple = tuple(my_list)
print(my_tuple)




