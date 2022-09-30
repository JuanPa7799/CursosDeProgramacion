from datetime import datetime
from random import randint

def execution_time(func):   
    def wraper(*args, **kwargs):
        initial_time = datetime.now()
        func(*args, **kwargs)
        final_time= datetime.now()
        time_elapsed = final_time -initial_time
        print ("Pasaron " + str(time_elapsed.total_seconds()) + " segundos")
    return wraper

@execution_time
def random_fun():
    for _ in range(1,100000000):
        pass
    
@execution_time
def suma (a: int, b: int) ->int:
    return a+b



@execution_time
def saludo(nombre="Cesar"):
    print("Hola " + nombre)
   
    
suma(5,5)  
random_fun()
saludo("Facundo")
    
    