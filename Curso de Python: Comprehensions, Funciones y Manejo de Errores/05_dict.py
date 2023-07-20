import random

dict ={}
for i in range(1 ,11):
    dict[i]=i * 2

print(dict)

#SIEMPRE AGRAGR CLAVE VALOR
dict_v2= { i: i*2 for i in range (1 ,11)}
print(dict_v2)


countries=[ 'col', 'mex', 'bol', 'pe']
population ={}
for country in countries:
    population[country] = random.randint  (1 , 100)


print(population)

population_v2 = { country: random.randint(1, 100) for country in countries}
print(population_v2)

names = [ "nico", "sule", "Juan"]
ages =[12, 56, 98]

{
    "nico" : 12,
    "sule" : 56,
    "Juan" : 98,
}

print (list(zip(names, ages)))

new_dict3 = { name: age for (name, age )in zip (names, ages)}
print(new_dict3)


