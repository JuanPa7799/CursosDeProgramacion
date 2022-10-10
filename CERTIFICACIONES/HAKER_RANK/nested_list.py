def badmatrix(n,m):
    a = [0]*m
    matriz = [a]*n
    return matriz


def run():
    c=int(input())
    M = badmatrix(c,2)
    i,j=0,0
    for _ in range(c):
        j=0
        name = input()
        score = float(input())
        M[i,j]=name
        j+=1
        M[i,j]=name
        i+=1
    print(M)        
    

if __name__=='__main__':
    run()




    