from account import Account

class Car:
    id           = int
    license      = str
    driver       = str
    passengenger = str
    
    def __init__(self, license, driver):
        self.license = license
        self.driver = driver
    