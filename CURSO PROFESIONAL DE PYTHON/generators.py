import time

def fibo_gen(max = None):
    n1 = 0
    n2 = 1
    aux2=n1+n2
    counter = 0
    while True:
        if counter == 0:
            counter +=1
            yield n1
        elif counter ==1:
            counter += 1
            yield n2
        elif aux2<=max:
            aux = n1 + n2
            n1, n2 =n2, aux
            counter += 1
            aux2=n1+n2
            yield aux
        else:
            raise StopIteration
            
            
if __name__ == '__main__':
    fibonacci = fibo_gen(13)
    for element in fibonacci:
        print(element)
        time.sleep(1)