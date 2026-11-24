*This project has been created as part of the 42 curriculum by abozhek, gtakhiro.*

# Push_swap

## Description

Push_swap is a C programming project in the 42 Common Core, the foundational
curriculum at 42. Students learn through practical projects and explain their
work in peer evaluations. See the [repository overview](../README.md) for
more about the curriculum.

The task is to sort a list of distinct integers using two stacks and a limited
set of moves. A stack has a top and a bottom. The first number on the command
line becomes the top of stack A, and the remaining numbers follow in the
order given. Stack B starts empty and serves as temporary storage. At the
end, A must contain the numbers from smallest to largest, top to bottom,
and B must be empty. The challenge is to reach that state with as few moves
as possible.

The project builds two command-line programs.

| Program | Role |
| --- | --- |
| `push_swap` | Generates a sequence of moves for the given numbers and prints one instruction per line. |
| `checker` | Replays a sequence of moves on the given numbers and reports whether it sorted them. This is the bonus program. |

For example, given `2 1 3`, `push_swap` prints `sa`. Swapping the top two
values in A turns `[2, 1, 3]` into `[1, 2, 3]` in one move.

The team earned the maximum score in the 42 project evaluation.

## Stack Operations

| Instruction | Effect |
| --- | --- |
| `sa` | Swap the top two values in A. |
| `sb` | Swap the top two values in B. |
| `ss` | Perform `sa` and `sb` together. |
| `pa` | Move the top value from B to the top of A. |
| `pb` | Move the top value from A to the top of B. |
| `ra` | Move the top value in A to the bottom. |
| `rb` | Move the top value in B to the bottom. |
| `rr` | Perform `ra` and `rb` together. |
| `rra` | Move the bottom value in A to the top. |
| `rrb` | Move the bottom value in B to the top. |
| `rrr` | Perform `rra` and `rrb` together. |

Each instruction counts as one move, including the combined instructions.
Swaps and rotations leave stacks with fewer than two values as they are.
A push from an empty stack has no effect. For combined instructions, each
stack is handled independently.

## Instructions

### Compilation

Run the examples from the `push_swap` directory. You need Make, a C compiler
available as `cc`, and a Unix-like environment such as Linux or WSL. The
examples use Bash. The Makefile builds with `-Wall -Wextra -Werror`. The two
executables build from the files in this directory and require no separate
Libft build or third-party library.

From the repository root, build both programs with:

```sh
cd push_swap
make all bonus
```

| Command | Result |
| --- | --- |
| `make`, `make all`, or `make push_swap` | Builds the main executable, `push_swap`. |
| `make bonus` or `make checker` | Builds the bonus executable, `checker`. |
| `make all bonus` | Builds both executables. |
| `make clean` | Removes object files for both executables. |
| `make fclean` | Removes the object files and both executables. |
| `make re` | Runs `fclean`, then rebuilds `push_swap`. Run `make bonus` afterward to rebuild `checker`. |

### Running `push_swap`

```text
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] [integers ...]
```

Pass numbers as separate arguments, as one quoted list, or as a mixture.
Whitespace inside a quoted list separates numbers. Each value is a distinct
decimal integer between `-2147483648` and `2147483647`. An optional leading
`+` or `-` must be followed by digits. Different spellings of the same
value, such as `1` and `+01`, count as duplicates.

```sh
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
./push_swap 4 "67 3" 87 23
./push_swap +7 -3 0
./push_swap -2147483648 2147483647
```

By default, `push_swap` uses the adaptive strategy. You can choose one strategy
explicitly and add `--bench` once. Flags must be separate arguments and can
appear before, between, or after the numbers. Use six or more unsorted values
to exercise the different sorting routines. Up to five values share the same
small-input routine.

```sh
./push_swap --simple 4 67 3 87 23 12
./push_swap --medium "4 67 3 87 23 12"
./push_swap --complex 4 67 3 87 23 12
./push_swap --adaptive 4 67 3 87 23 12
./push_swap 4 67 --medium 3 87 23 12 --bench
```

The move list goes to standard output (stdout). With no arguments, one
number, or an already sorted list, there are no moves to print. A run
containing only valid flags represents empty input. If one of those flags
is `--bench`, the program prints a report with zero moves.

Duplicate values, empty or whitespace-only arguments, malformed numbers,
out-of-range values, unknown flags, and repeated or conflicting flags produce
`Error` on standard error (stderr) and exit with status `1`.

```sh
./push_swap 1 +01
./push_swap ""
./push_swap "   "
./push_swap 12x
./push_swap 2147483648
./push_swap --simple --medium 2 1
```

### Benchmarking

Add `--bench` to report the original disorder as a percentage with two
decimal places, the requested strategy and its selected move complexity,
the total number of moves, and a count for each of the eleven instructions.
This measures moves. It does not time the program.

```sh
./push_swap --adaptive --bench 4 67 3 87 23 12
./push_swap --bench 1 2 3
```

The move list goes to stdout and the benchmark report goes to stderr.
You can count the moves directly with `wc -l`, or save the two streams to
separate files.

```sh
./push_swap 4 67 3 87 23 12 | wc -l
./push_swap --bench 4 67 3 87 23 12 > moves.txt 2> benchmark.txt
```

### Running the Bonus Checker

```text
./checker [integers ...]
```

`checker` accepts the same number formats and validation rules as
`push_swap`. Give it the original numbers in their original order. It takes
only numbers as arguments and reads moves from standard input (stdin).
Use one instruction per line, with a newline after the final instruction.
After end of input (EOF), the checker prints the result.

| Result | Meaning | Stream | Exit status |
| --- | --- | --- | --- |
| `OK` | A is sorted in ascending order and B is empty. | stdout | `0` |
| `KO` | The moves were valid, but A is unsorted or B still contains values. | stdout | `0` |
| `Error` | A number or instruction is invalid, or reading the instructions failed. | stderr | `1` |

A script should read the result text to distinguish `OK` from `KO`.
Unknown instructions, blank lines, extra spaces, and a missing final newline
are errors. With no arguments, the checker exits silently without reading
stdin.

#### Pipe moves directly from `push_swap`

```sh
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
./push_swap --complex --bench "4 67 3 87 23 12" | ./checker "4 67 3 87 23 12"
```

Both commands print `OK`. The second also displays the benchmark report
on the terminal because the pipe carries only stdout. For repeated Bash runs,
an array keeps the two argument lists in sync.

```bash
numbers=(4 67 3 87 23 12)
./push_swap --medium "${numbers[@]}" | ./checker "${numbers[@]}"
```

#### Save and replay a move list

```sh
./push_swap --bench 4 67 3 87 23 > moves.txt 2> benchmark.txt
./checker 4 67 3 87 23 < moves.txt
```

Use plain text with Unix line endings (LF) when writing a move file by hand.

#### Provide moves yourself

```sh
printf 'sa\n' | ./checker 2 1 3  # OK
printf 'pb\n' | ./checker 1 2    # KO (B contains a value)
printf 'xyz\n' | ./checker 2 1   # Error (unknown instruction)
printf 'sa' | ./checker 2 1      # Error (missing final newline)
./checker 1 2 3 < /dev/null      # OK (already sorted)
./checker 2 1 3 < /dev/null      # KO (still unsorted)
```

You can also start `./checker 2 1 3` in a terminal, type `sa`, press
Enter, and then press Ctrl+D on the empty line to send EOF. The checker
prints `OK`.

### Testing with the Supplied Linux Checker

[`checker_linux`](./checker_linux) is a prebuilt x86-64 Linux executable
distributed with the 42 assignment. The team used it to validate
`push_swap` before implementing the bonus `checker`, then compared the
bonus program's results against it.

On a compatible Linux system, build just the sorter and pipe its moves
into the supplied executable. The checker receives the same numbers in the
same order.

```sh
make
./push_swap 4 67 3 87 23 | ./checker_linux 4 67 3 87 23
```

The example prints `OK`. If the supplied file lacks execute permission,
run `chmod +x checker_linux` before using it.

To compare the two checkers, generate the moves once and give both programs
the same file and starting values.

```sh
make all bonus
./push_swap 4 67 3 87 23 > moves.txt
./checker_linux 4 67 3 87 23 < moves.txt
./checker 4 67 3 87 23 < moves.txt
```

Both programs should print `OK` for this input.

### Generating Test Inputs with `shuf`

On Linux, GNU Coreutils provides `shuf`. Use `-i` to specify an inclusive
range and `-n` to select a number of distinct values from that range. Each
file below contains one number per line.

```sh
shuf -i 1-10000 -n 200 > numbers-200.txt
wc -l numbers-200.txt
```

`wc -l` prints the number of lines in the file.

```text
200 numbers-200.txt
```

In Bash, `mapfile -t` reads one number per line into an array and removes
the line endings. Expanding the array as `"${numbers[@]}"` passes each
number as a separate argument, a format accepted by both checkers. Reuse
the same array to keep the starting values and their order identical.

```bash
make all bonus
mapfile -t numbers < numbers-200.txt
./push_swap --bench "${numbers[@]}" > moves-200.txt
./checker "${numbers[@]}" < moves-200.txt
./checker_linux "${numbers[@]}" < moves-200.txt
wc -l < moves-200.txt
```

Output from one run with 200 numbers:

```text
[bench] disorder: 48.70%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 2036
[bench] sa: 0  sb: 0  ss: 0  pa: 200  pb: 200
[bench] ra: 1191  rb: 229  rr: 0  rra: 0  rrb: 216  rrr: 0
OK
OK
2036
```

The benchmark stays visible in the terminal because it goes to stderr.
At 48.70% disorder, the adaptive strategy chose the medium algorithm.
The first `OK` comes from the bonus `checker` and the second from
`checker_linux`. The final `2036` is the number of lines in
`moves-200.txt` and matches `total_ops`. New random inputs can produce a
different disorder, strategy, and move count.

Keep the input file to replay the exact same test later. Running
`shuf` again generates a new random sample and overwrites the file if you
reuse its name with `>`.

### Evaluation Benchmarks

Section VI.6 of the 42 assignment gives the following move-count targets
for random inputs. Each limit is strict.

| Input size | Passing | Good | Excellent |
| ---: | ---: | ---: | ---: |
| 100 numbers | < 2,000 | < 1,500 | < 700 |
| 500 numbers | < 12,000 | < 8,000 | < 5,500 |

With both executables built, run the same test at the two evaluation sizes.
The benchmark appears on the terminal and the moves are saved for replay.

```bash
for size in 100 500; do
    shuf -i 1-10000 -n "$size" > "numbers-$size.txt"
    mapfile -t numbers < "numbers-$size.txt"
    ./push_swap --bench "${numbers[@]}" > "moves-$size.txt"
    ./checker "${numbers[@]}" < "moves-$size.txt"
    ./checker_linux "${numbers[@]}" < "moves-$size.txt"
done
```

**100 numbers**

```text
[bench] disorder: 49.82%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 801
[bench] sa: 0  sb: 0  ss: 0  pa: 100  pb: 100
[bench] ra: 433  rb: 89  rr: 0  rra: 0  rrb: 79  rrr: 0
OK
OK
```

**500 numbers with disorder above 50%**

This sample was selected from repeated random draws to demonstrate the
adaptive switch to binary radix sort.

```text
[bench] disorder: 50.66%
[bench] strategy: Adaptive / O(n log n)
[bench] total_ops: 6784
[bench] sa: 0  sb: 0  ss: 0  pa: 2284  pb: 2284
[bench] ra: 2216  rb: 0  rr: 0  rra: 0  rrb: 0  rrr: 0
OK
OK
```

Both sample runs reached the good-performance tier. The move count depends
on the generated input.

## Algorithms and Data Structures

### Ranking and Measuring Disorder

The program validates its inputs and gives each number a rank based on how
many input values are smaller. For example, `40 -10 7` becomes `2 0 1`.
Ranks preserve the order of the original values and give every input the rank
range from `0` to `n - 1`, where `n` is the number of values.

The program also counts pairs that appear in the wrong order. In
`3 1 2`, the pairs `(3, 1)` and `(3, 2)` are out of order. Two out of
three pairs gives a disorder of `66.67%`. A sorted list has zero disorder.
A reverse-sorted list of at least two distinct values has 100% disorder.
The program defines disorder as zero for lists shorter than two values.

### Sorting Strategies

| Selector | Method | Move upper bound |
| --- | --- | --- |
| `--simple` | Move the smallest remaining values out of A one at a time. | O(n²) |
| `--medium` | Move consecutive groups of ranks to B, then return them in order. | O(n√n) |
| `--complex` | Sort by the binary digits of the ranks. | O(n log n) |
| `--adaptive` | Choose one of the three methods from the original disorder. | Depends on the selected method. |

- **Simple.** Find the smallest value in A, rotate it to the top using the
  shorter direction, and push it to B. Repeat while more than three values
  remain and A still needs sorting. Sort the remaining values if necessary,
  then push B back to A so the smallest value ends up on top. There are at
  most n extractions, each with at most O(n) rotations, for O(n²) moves.
- **Medium.** Split the ranks into groups about √n values wide. Process the
  groups from lowest to highest, rotating A until a value in the current
  group reaches the top and then pushing it to B. Rotate values in the lower
  half of each group to the bottom of B. To rebuild A, repeatedly bring
  B's largest remaining value to the top and push it to A. For a group
  width k, collecting each group takes at most one pass through the remaining
  A, for O(n²/k) moves overall. In B, each group lies in two runs around
  the earlier groups. Removing it costs O(k²) moves within those runs
  and at most O(n) moves to cross the earlier groups between the runs.
  Over all groups the total is O(nk + n²/k), which becomes O(n√n) with
  a group width of about √n.
- **Complex.** Use binary radix sort, starting with the rightmost bit of each
  rank. For each bit, push values with a zero to B and rotate values with a
  one in A. Return every value in B to A. Each pass keeps the relative order
  within the two groups, so processing the bits from right to left sorts the
  ranks. There are at most ⌈log₂(n)⌉ passes for an unsorted input, with
  at most 2n moves per pass.
- **Adaptive.** Measure disorder once before moving anything. Use simple
  below 20%, medium from 20% up to but excluding 50%, and complex from
  50% upward. These thresholds come from the assignment. For low disorder,
  simple extraction can stop as soon as what remains in A is sorted. For
  medium disorder, processing ranks in groups reduces repeated passes over
  A. For high disorder, radix sort gives a predictable limit on the number
  of passes. The decision uses the original fraction before the percentage
  is rounded for display.

All modes skip sorting when A is already sorted. Unsorted inputs of at most
five values use the small minimum-extraction routine. The benchmark still
reports the chosen strategy and its move complexity for these cases.

### Move Count, Runtime, and Storage

The bounds in the strategy table describe how many instructions the program
can emit as the input grows. The program also spends time validating values,
computing ranks, and measuring disorder. These steps compare pairs of values
and take O(n²) time. The simple and medium strategies also scan their stacks
to find the next minimum or maximum.

Each stack uses a circular array. The program tracks the top by index, so a
rotation can update the index and move one value instead of shifting the
whole array. Each stack instruction takes constant time to apply in memory.
The arrays for the stacks and temporary ranks take O(L) space, where L is
the length of the command-line input text. This is O(n) for ordinary
fixed-width integer arguments with bounded whitespace per value. All
sorting strategies use constant extra workspace beyond the arrays and
write each instruction as it goes.

### Source Files

| File | Responsibility |
| --- | --- |
| `main.c` | Main entry point, strategy selection, and sorting flow. |
| `parse.c` | Argument parsing, flag handling, and number validation. |
| `rank.c` | Duplicate detection, rank conversion, and disorder measurement. |
| `stack.c` | Circular stacks and instruction execution. |
| `names.c` | Instruction names shared by the sorter and checker. |
| `sort.c` | Sortedness checks, small-input sorting, minimum extraction, and radix sorting. |
| `medium.c` | Group-based sorting. |
| `bench.c` | Benchmark reporting. |
| `checker_bonus.c` | Bonus entry point, instruction reading, and result reporting. |
| `utils.c` | Output, comparison, memory cleanup, and error handling. |
| `push_swap.h` | Shared data structures and function declarations. |
| `Makefile` | Build and cleanup rules for both programs. |

## Resources

- **42 Push_swap project subject (v1.2)** — rules, strategy requirements,
  and evaluation criteria. [PDF](../subjects/push_swap.pdf)
- **Thomas H. Cormen et al., *Introduction to Algorithms*** — inversions,
  sorting methods, and how to describe their complexity.
- **Donald E. Knuth, *The Art of Computer Programming*, Volume 3** — sorting methods.
- **Unix manual pages** — `man 1 make`, `man 2 read`, `man 2 write`,
  `man 3 malloc`, and `man 3 free`.
- **Norminette** — if installed, run `norminette *.c *.h` from this directory
  to check the C files and header against the 42 coding style.

### AI Usage

AI tools were used for studying and code review.
