def sum_whit_range(min, max):
    print(min, max)
    sum = 0
    for x in range(min,max):
        sum += x
    return sum
    #1,2,3,4,5,6...


result=sum_whit_range(1,10)
print(result)
result_2=sum_whit_range(result, result+10)
print(result_2)

