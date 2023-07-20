numbers = []
for element in range(1,11):
    numbers.append(element*2)
    
print(numbers)

numbers_v2 = [element * 2 for element in range (1,11)]
print(numbers_v2)

numbers2 = []
for i in range(1,11):
    if i % 2 == 0:
        numbers2.append(i*2)
    
print(numbers2)

numbers2_v2 = [i * 2 for  i in range (1, 11) if i % 2 == 0] 
print(numbers2_v2)

 


