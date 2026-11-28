def countdown(day, last_day):
    if day > last_day:
        return
    print(f"Day {day}")
    countdown(day + 1, last_day)


def ft_count_harvest_recursive():
    last_day = int(input("Days until harvest: "))
    countdown(1, last_day)
    print("Harvest time!")
