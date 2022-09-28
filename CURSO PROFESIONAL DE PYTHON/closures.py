from timeit import repeat
from unittest.util import strclass


def make_repeater_of(n):
    def repeater(String):
        assert type(String) == str, "Solo puedes ingresar cadenas"
        return String * n
    return repeater

def run():
    repeat_5 = make_repeater_of(5)
    print(repeat_5("Hola"))
    repeat_10 = make_repeater_of(10)
    print(repeat_10("Platzi"))

if __name__=='__main__':
    run()