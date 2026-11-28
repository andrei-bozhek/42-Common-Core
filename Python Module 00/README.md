*This project has been created as part of the 42 curriculum by abozhek.*

English | [日本語](README.ja.md)

# Python Module 00 — Growing Code

## Description

Growing Code introduces Python fundamentals through community garden data.
The eight exercises cover console input and output, integer arithmetic,
conditionals, loops, recursion, and type annotations.

## Exercises

| Exercise | Source | Task |
| --- | --- | --- |
| ex0 | [`ft_hello_garden.py`](ex0/ft_hello_garden.py) | Print a welcome message. |
| ex1 | [`ft_garden_name.py`](ex1/ft_garden_name.py) | Read a garden name and display it with a status message. |
| ex2 | [`ft_plot_area.py`](ex2/ft_plot_area.py) | Calculate the area of a rectangular plot. |
| ex3 | [`ft_harvest_total.py`](ex3/ft_harvest_total.py) | Add three daily harvest weights. |
| ex4 | [`ft_plant_age.py`](ex4/ft_plant_age.py) | Check whether a plant is more than 60 days old. |
| ex5 | [`ft_water_reminder.py`](ex5/ft_water_reminder.py) | Recommend watering when more than two days have passed. |
| ex6 | [Iterative](ex6/ft_count_harvest_iterative.py), [recursive](ex6/ft_count_harvest_recursive.py) | Print each day from 1 through the harvest day using a loop or recursion. Both versions produce the same output. |
| ex7 | [`ft_seed_inventory.py`](ex7/ft_seed_inventory.py) | Format a seed inventory entry by unit using a function with type annotations. |

## Instructions

Use Python 3.10 or later. Run the supplied test menu from the repository root
with the exercise directories on Python's import path.

```sh
cd "Python Module 00"
PYTHONPATH=ex0:ex1:ex2:ex3:ex4:ex5:ex6:ex7 python3 main.py
```

Choose `0` through `7` for one exercise or `a` for all exercises. Option `6`
prompts for the number of days twice, once per implementation. Option `7`
supplies sample arguments for packets, grams, area, and an unknown unit.

### Code Checks

With `flake8` and `mypy` installed, run these commands from the module directory.

```sh
flake8 ex[0-7]/ft_*.py
mypy ex7/ft_seed_inventory.py
```

## Resources

- **42 Growing Code subject** — Exercise requirements and sample output. [PDF](../subjects/Python%20Module%2000.pdf)
- **W3Schools** — Python basics with examples and practice exercises. [Python Tutorial](https://www.w3schools.com/python/)

### AI Usage

No AI was used.
