my_dict= {}
print(type(my_dict))

my_dict = {
    'avion': "bla bla bla",
    'name': "JuanPa",
    'last_name': "Garcia Chavez",
    'age': "24",
    
}
print(my_dict)
print(len(my_dict))

print(my_dict['age'])
print(my_dict['last_name'])
print(my_dict.get('age'))
print(my_dict.get('unvalor')) #SI NO EXISTE CON UN GET DA UN NONE DE QUE NO EXISTE EN LUGAR DE UN ERROR


print('avion' in my_dict)
print('otroqueno' in my_dict)


