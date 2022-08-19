def run():
    n = int(input())
    arr = map(int, input().split())
    numero_memo=0
    numero_mayor=0
    for numero in arr:
        arr2=arr2.append(numero)
        if numero > numero_mayor:
            numero_mayor=numero
        
    for i in range(0,len(arr2)):
        print(arr2)
        if arr2[i] > numero_memo and arr2[i]  < numero_mayor:
            numero_memo=arr2[i] 
        
    print(numero_memo)

if __name__ == '__main__':
    run()