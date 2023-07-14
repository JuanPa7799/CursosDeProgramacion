# for element in range(20):
#     print(element)
    
# for element in range(5, 21):
#     print(element)
    
my_list = [23, 45, 67, 89, 43]
for elemnt in my_list:
    print(elemnt)
    
my_tuple=("nico", "juli", "juanpa")
for elemnt in my_tuple:
    print(elemnt)
    
my_dict =  {
    "name": "Camisa",
    "priece": 100,
    "stock": 89,
}
for key in my_dict:
    print(my_dict[key])


for key, value in my_dict.items():
    print(key, "=>", value)
    
    
#LO MAS COMUN ES RECIBIR UNA LISTA DE DICCIONARIOS


people = [
    {
        "name": "nico",
        "age": "34",
    },
    {
        "name": "juanpa",
        "age": "24",
    },
    {
        "name": "zule",
        "age": "45",
    }
]    

for person in people:
    print("name =>",person["name"])


    
