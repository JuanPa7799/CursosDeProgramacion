person = {
    'name': "Juan",
    'last_name': "Garcia",
    'langs': ["python", "javascript"],
    'age': 99,
}
print(person)

person['name'] = "JuanPa"
print(person)

person['age'] -= 50
print(person)

person['langs'].append('rust')
print(person)

del person['last_name']
person.pop('age')
print(person)

print("Items =>",person.items())
print("Keys =>",person.keys())
print("Values =>",person.values())


