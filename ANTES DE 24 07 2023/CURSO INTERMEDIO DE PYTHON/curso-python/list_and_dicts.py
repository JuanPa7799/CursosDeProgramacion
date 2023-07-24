def run():
    my_list = [1, 'Hello', True, 4.5]
    my_dict = {"fistname": "Juan", "lastname": "García"}
    super_list=[
        {"fistname": "Juan", "lastname": "García"},
        {"fistname": "Miguel", "lastname": "Lopez"},
        {"fistname": "Carlos", "lastname": "Andrade"},
        {"fistname": "Pepe", "lastname": "Martínez"},
        {"fistname": "Susana", "lastname": "García"},
    ]
    
    super_dict = {
        "natural_nums": [1,2,3,4,5],
        "integer_nums": [-1, -2, 0, 1, 2],
        "floating_nums":[1.1, 4.5, 6.43]
    }
    
    for key, value in super_dict.items():
        print(key, "-",value)
    

if __name__=='__main__':
    run()