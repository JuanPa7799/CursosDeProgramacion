def run():
    n = int(input())
    arr = map(int, input().split())
    numero_memo=-10000
    numero_mayor=-10000
    a =  list(arr)
    for numero in a:
        if numero > numero_mayor:
            numero_mayor=numero
        
    for i in a:
        if i > numero_memo and i  < numero_mayor:
            numero_memo=i
        
    print(numero_memo)

if __name__ == '__main__':
    run()