
<h1 align="center">42 Tokyo — Common Core</h1>

<p align="center">
  My software engineering journey through the 42 Common Core curriculum.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/42-Tokyo-000000?style=flat-square" alt="42 Tokyo">
  <img src="https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/Language-Python-3776AB?style=flat-square&logo=python&logoColor=white" alt="Python">
  <img src="https://img.shields.io/badge/2026-Present-555555?style=flat-square" alt="2026 - Present">
</p>

English | [日本語](README.ja.md)

## About 42

[42 Tokyo](https://42tokyo.jp/) is a peer-to-peer software engineering school based on project-based learning.

Students learn through independent research, practical programming challenges, collaboration, and peer evaluation rather than traditional lectures.

## About the Common Core

The **Common Core** is the foundational curriculum of 42, focused on programming, algorithms, Unix systems, software engineering, and problem solving.

This repository documents my projects and progress throughout the curriculum.

## Projects

| Project | Description | Subject |
|:---|:---|:---:|
| [Libft](./Libft/) | Build a reusable C library by recreating standard library functions and implementing additional utilities | [PDF](./subjects/Libft.pdf) |
| [ft_printf](./ft_printf/) | Recreate core `printf` conversions using variadic arguments, format parsing, and decimal and hexadecimal output | [PDF](./subjects/ft_printf.pdf) |
| [get_next_line](./get_next_line/) | Read from a file or standard input one line at a time using buffered reading, static variables, and dynamic memory allocation | [PDF](./subjects/get_next_line.pdf) |
| [push_swap](./push_swap/) | Sort integers with two stacks and 11 allowed operations, select a strategy based on input disorder, and verify the result with a bonus checker | [PDF](./subjects/push_swap.pdf) |
| [Python Module 00](./Python%20Module%2000/) | Practice Python input and output, conditionals, loops, recursion, and type annotations with community garden data | [PDF](./subjects/Python%20Module%2000.pdf) |

## Tests

My testers for Libft and ft_printf are maintained in a separate repository. See the [42 Common Core Tests README](https://github.com/andrei-bozhek/42-Common-Core-Tests/blob/main/README.md) for usage instructions.

The Push_swap README includes commands for generating test inputs, measuring operation counts, and checking the results with both the bonus checker and the Linux checker supplied with the assignment. [Push_swap testing instructions](./push_swap/README.md#testing-with-the-supplied-linux-checker)

The Python Module 00 README shows how to run the supplied test menu and check the exercises with `flake8` and `mypy`. [Python Module 00 instructions](./Python%20Module%2000/README.md#instructions)

## Skills & Technologies

- **Languages:** C, Python
- **Tools:** Git, Make, Unix shell
- **Concepts:** Memory management, pointers, algorithms, modular programming, variadic functions, formatted output, file descriptors, buffered reading, static variables, stack operations, adaptive sorting, algorithmic complexity

This section will grow as new projects are completed.

## Repository Structure

Each project has its own directory with source code, English and Japanese README files, and a Makefile where required. Subject PDFs are stored in the shared [subjects](./subjects/) directory.

## Previous Journey

Before starting the Common Core, I completed the intensive **42 Tokyo C Piscine**.

[Explore my 42 Piscine repository](https://github.com/andrei-bozhek/42-Piscine)
