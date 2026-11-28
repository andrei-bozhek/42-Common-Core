def ft_count_harvest_iterative():
    until_harvest = range(1, int(input("Days until harvest: ")) + 1)
    for day in until_harvest:
        print(f"Day {day}")
    print("Harvest time!")
