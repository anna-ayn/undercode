s = int(input(), base=2)
d = int(input(), base=2)
m = int(input(), base=2)

day = 0
total = m

list_salary = []

while total > 0:
    total = total // 2
    if day % d == d - 1:  # llego el dia de pago
        total += s
        list_salary.append(total)

        print(total)

        if len(list_salary) > 1:
            if list_salary[len(list_salary) - 1] >= list_salary[len(list_salary) - 2]:
                print("Infinite money!")
                exit()
    day += 1

print(bin(day)[2:])  # bin(day) = '0b1010' -> bin(day)[2:] = '1010'
