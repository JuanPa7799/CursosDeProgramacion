def run():
    # my_dict ={}
    # for i in range(1,101):
    #     if i %3 !=0:
    #         my_dict[i]=i**3
        
        
    # print(my_dict)
    my_dict = {i: i**3 for i in range(1,101) if i%3 !=0 }
    print(my_dict)
    raiz = {i: i**(1/2) for i in range(1,1001)}
    print(raiz)
    
if __name__=='__main__':
    run()
    
