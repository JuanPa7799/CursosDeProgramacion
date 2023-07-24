x = 3.3
print (x)
y = 1.1 +2.2
print(y)
print (x == y)

y_string = format(y,".2g")
print(y_string)
print (str(x) == y_string)
print (x == float(y_string))

tolerance=0.00001
print(abs(x - y)<tolerance)