name = "Juanpa"
last_name= "García Chávez"
print(name)
print(last_name)

full_name= name + " " + last_name
print(full_name)

quote = 'I\'m JuanPa'
print (quote)

quote2 = 'She said "Hello"'
print(quote2)

# Format

template = "Hola, mi nombre es " + name + " y mi apellido es " +last_name
print(template)

template = "Hola, mi nombre es {} y mi apellido es {}".format(name, last_name)
print(template)

template = f"Hola, mi nombre es {name} y mi apellido es {last_name}"
print(template)

