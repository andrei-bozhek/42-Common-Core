def ft_harvest_total():
    day_1_harvest = input("Day 1 harvest: ")
    day_2_harvest = input("Day 2 harvest: ")
    day_3_harvest = input("Day 3 harvest: ")
    print(
        f"Total harvest: "
        f"{int(day_1_harvest) + int(day_2_harvest) + int(day_3_harvest)}"
    )
