from faker import Faker
import random
fake = Faker()
f = open('data1.txt', "w")

for _ in range(1):
    home = fake.bothify(text = '?', letters=["house", "dorm"])
    name = fake.first_name()
    surname = fake.last_name()
    group = random.randint(1, 100)
    gender = random.choice(["m", "f"])
    age = random.randint(1, 100)
    arithmetic_mean = random.uniform(0, 100)
    day = random.randint(1, 28)
    month = random.randint(1, 12)
    entry_day = (('0' + str(day)) if (day < 10) else (str(day))) + '.' + (('0' + str(month)) if (month < 10) else str(month)) + '.' + str(random.randint(1990, 2022))
    house = fake.street_suffix() + ' ' + fake.building_number() + ' ' + fake.building_number()
    dorm = str(random.randint(1, 15)) + ' ' + fake.building_number()
    f.write("{:>5} {:>15} {:>15} {:>5} {:>5} {:>5} {:>20} {:>15} {:>15}\n".format(home, surname, name, group, gender, age, arithmetic_mean, entry_day, house if (home == "house") else dorm))
    #print("{:>5} {:>15} {:>15} {:>5} {:>5} {:>5} {:>20} {:>15} {:>15}".format(home, surname, name, group, gender, age, arithmetic_mean, entry_day, house if (home == "house") else dorm))
