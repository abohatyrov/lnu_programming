# Дано послідовність слів, відокремлених комами. Змінити стрічку так, щоб усі слова 
# починалися з великої літери, а всі інші літери були малими. Вивести змінену стрічку 
# на екран.
s = ", ".join([ w.capitalize() for w in input("Enter string (, - sep): ").split(", ") ])
print(s)


# Ввести масив різних цілих чисел. Знайти два найменших елементи масиву.
a = [ int(i) for i in input("Enter array: ").split() ]
min1 = min(a)
min2 = min(a, key=lambda value: value if value != min1 else max(a))
print(f"min1 = {min1}\nmax2 = {min2}")


# Ввести список з n номерів квартир та кількість спожитої електроенергії за поточний 
# місяць (наприклад, 25 – 150 кВт/год). Утворити словник з пар “номер квартири –
# вартість електроенергії в поточному місяці” , яка обчислюється наступним чином: 
# до 100 кВт/год – 90 коп. за кВт/год; понад 100 кВт/год – 168 коп. за кВт/год. 
# Вивести номер квартири з найбільшим рахунком за електроенергію.
n = int(input("Enter n: "))
lst = [ (int(input(f"Enter {i+1} apartment number: ")), int(input(f"Enter {i+1} user data: "))) for i in range(n) ]
pills = {}
for k, v in lst:
    pills[k] = 90 * v / 100 if v <= 100 else 168 * v / 100

pills = dict(sorted(pills.items(), key=lambda value: value[1], reverse=True))
print(f"Apartment number with the highest bill: {list(pills.keys())[0]}")
