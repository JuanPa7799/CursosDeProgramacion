function newUser(name, age, country) {
    var name = name || "Oscar";
    var age = age || 24;
    var country = country || "MX";
    console.log(name, age, country);
    
}

newUser();
newUser("David", 23, "CO");

function newAdmin(name = "oscar", age = 33, country="CL" ) {
    console.log(name, age, country);
}
newAdmin();
newAdmin("Juan", 24, "MX");