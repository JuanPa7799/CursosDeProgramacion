if __name__ == '__main__':
    N = int(input())

    lis=[]
    
    for i in range(N):
        ins=input()
        if ins[0]=="i":
            if len(ins)==10:
                lis.insert(int(ins[7]),int(ins[9]))
            elif len(ins)==11:
                lis.insert(int(ins[7]),int((ins[9])+(ins[10])))
        elif ins[0]=="p" and ins[1]=="r":
            print(lis)
        elif ins[0]=="r" and ins[2]=="m":
            lis.remove(int(ins[7]))
        elif ins[0]=="a":
            if len(ins)==8:
                lis.append(int(ins[7]))
            elif len(ins)==9:
                lis.append(int(ins[7]+ins[8]))
            
        elif ins[0]=="s":
            lis.sort()
        elif ins[0]=="p" and ins[1]=="o":
            lis.pop()
        elif ins[0]=="r" and ins[2]=="v":
            lis.reverse()
                
