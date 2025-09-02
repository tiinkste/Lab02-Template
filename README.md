# Lab 2 - Simple I/O and Debugging

## Introduction

You've been recruited by SomeCorp, a small local business. SomeCorp is in need of your expertise to modernize their storefront infrastructure.

SomeCorp has high expectations of your code quality, as do we: **If encountering any invalid input, the program should terminate immediately with a non-zero exit code.** While it is best practice to print an error message in many cases, you should not do so in this lab but simply terminate your program.

## Part 1

### Overview

Your first task at SomeCorp is to help them create a new checkout program for their stores. This program must be written (from the **current directory** you are working in; this is the default setting) in the source directory named `src`, and in a source-code file named `ex2q1.c`. The full path should be `src/ex2q1.c` (again, from the current directory).

To keep the initial test small scale, SomeCorp is aiming to deploy the program at one of their small locations which only sells 4 items: Apples, Carrots, Chips, and Candy. The data for each product is given in the following table.

| Product | Cost     | Available Quantity |
| ------- | -------- | ------------------ |
| Apples  | $5.99/kg | 7.2kg              |
| Carrots | $3.99/kg | 4.1kg              |
| Chips   | $2.99/bag| 9                  |
| Candy   | $1.50    | 3                  |

### Promotions

SomeCorp has some special promotions that occur in their stores at times. Your program will need to account for and apply the necessary discounts on the items if they are applicable. Here are the deals:

- For every 2 bags of chips purchased, get 1 candy 50% off!
- Buying at least 1kg / 1unit of every of the four items, gets 10% off your entire order!

Note that the deals are applied in the order listed here if both of them apply.

### Your Tasks

Your program should prompt the user for the quantity of these items they'd like to buy, and then calculate and display a receipt in a nice table. The prices of Apples and Carrots are measured in $/kg and as such, your program should prompt for the quantities of those items in weight (as a float). The subtotal before tax should then be printed along with subtracting any applicable promotions that apply to the total. A 5% tax is then added onto that value before displaying the final total.

Here is the format of the input prompt:

```
Apples     (7.20  kg) : <float>
Carrots    (4.10  kg) : <float>
Chips      (9  units) : <int>
Candy      (3  units) : <int>
```

After displaying and getting input, print a new line, and then print out the reciept table as follows:

```
-------------------------------------------------------------------
| Item     | Quantity     | Cost       | Discount    | Total      |
| <1>      | <float>   kg | $  <float> | -$  <float> | $  <float> |
| <2>      | <int>        | $  <float> | -$  <float> | $  <float> |
| ...      | ...          | ...        | ...         | ...        |
-------------------------------------------------------------------
```

The dollar costs are right aligned while the quantities are left aligned. The units for weight should always be placed to the right as depicted above.

For items that are measured by weight, format 1 is followed (the only difference is quantity is measured in kg and is a floating point number). Other items follow format 2. Note that all dollar amounts and weights should be printed to two decimal places.

Note that if the customer does not purchase a particular item (i.e. its quantity is zero), it should not appear in the table.

The cost column is simply the cost of the item multiplied by how many they bought.

The discount column measures whether the customer gets any amount off that applies to that specific item. Note that any promotions that apply to the entire order **are not** represented in this column.

The total column is obtained simply by taking the cost of the item minus any applicable discounts for the item.

After printing the table, print a new line, and then the following section:

```
Subtotal        : $<float> - $<float> = $<float>
Tax (5%)        : $<float>
----------------------------------------------------
Total           : $<float>
```

The subtotal is the sum of the total column from the previous table. If any promotions that apply to the whole order are applicable, they are then subtracted here. If no promotions apply, the subtotal simply appears as one number like so:

```
Subtotal        : $<float>
```

The tax is 5% of the final subtotal.

The total is the final subtotal + the amount of the tax.

### Input Handling

The values for Apples and Carrots are in weight and thus are floating point values. Thus, they should be read in as floats. Chips and candy are unit counts and thus are integers. They should be read in as integers. In this lab, we define **valid input** as successfully read in input that is within the required range. For example, typing the character `a` when asked for the quantity of apples will not read in successfully (and is therefore invalid). All input should be >= `0` and <= the available quantity. All other input is considered invalid and should be treated accordingly by **terminating immediately with a non-zero exit code**.

### Example I/O

Your program should match the Example I/O **exactly** to obtain marks.

```
Apples     (7.20  kg) : 2
Carrots    (4.10  kg) : 1
Chips      (9  units) : 2
Candy      (3  units) : 1

-------------------------------------------------------------------
| Item     | Quantity     | Cost       | Discount    | Total      |
| Apples   | 2.00      kg | $    11.98 | -$     0.00 | $    11.98 |
| Carrots  | 1.00      kg | $     3.99 | -$     0.00 | $     3.99 |
| Chips    | 2            | $     5.98 | -$     0.00 | $     5.98 |
| Candy    | 1            | $     1.50 | -$     0.75 | $     0.75 |
-------------------------------------------------------------------

Subtotal        : $22.70 - $2.27 = $20.43
Tax (5%)        : $1.02
----------------------------------------------------
Total           : $21.45
```

```
Apples     (7.20  kg) : 7.1
Carrots    (4.10  kg) : 0
Chips      (9  units) : 3
Candy      (3  units) : 0

-------------------------------------------------------------------
| Item     | Quantity     | Cost       | Discount    | Total      |
| Apples   | 7.10      kg | $    42.53 | -$     0.00 | $    42.53 |
| Chips    | 3            | $     8.97 | -$     0.00 | $     8.97 |
-------------------------------------------------------------------

Subtotal        : $51.50
Tax (5%)        : $2.57
----------------------------------------------------
Total           : $54.07
```

```
Apples     (7.20  kg) : 1.01
Carrots    (4.10  kg) : 1.57
Chips      (9  units) : 1
Candy      (3  units) : 3

-------------------------------------------------------------------
| Item     | Quantity     | Cost       | Discount    | Total      |
| Apples   | 1.01      kg | $     6.05 | -$     0.00 | $     6.05 |
| Carrots  | 1.57      kg | $     6.26 | -$     0.00 | $     6.26 |
| Chips    | 1            | $     2.99 | -$     0.00 | $     2.99 |
| Candy    | 3            | $     4.50 | -$     0.00 | $     4.50 |
-------------------------------------------------------------------

Subtotal        : $19.80 - $1.98 = $17.82
Tax (5%)        : $0.89
----------------------------------------------------
Total           : $18.71
```

```
Apples     (7.20  kg) : 1.01
Carrots    (4.10  kg) : 1.57
Chips      (9  units) : 10
```

Note: This input ends the program with a non-zero exit code.

```
Apples     (7.20  kg) : 0
Carrots    (4.10  kg) : 0
Chips      (9  units) : 0
Candy      (3  units) : 0
```

Note: This input ends the program with exit code 0 (customer buying nothing is a valid choice).


## Part 2

### Overview

After the success of your checkout program, SomeCorp assigns you to help with their mobile delivery service. As it turns out, their system is unable to properly assign drivers to the closest delivery points. To help with this, your task is to create a program that takes in as input three pairs of $(x, y)$ coordinates. Then, you will output which two points are the closest to each other and their distance.

Since computing the distance between two points requires using a square root function, you will have to use `sqrtf()` from `math.h`. This function takes in a `float` as an argument and returns the square root of the number. In order to use this library, you must `#include` it in your code and compile your program using the linking flag `-lm`. Note that linking flags must appear at the end of your `gcc` command, or else they will not work.

Note that there are many different ways to take a square root using `math.h`. You may notice that there are three different square root functions, `sqrtf()`, `sqrt()`, and `sqrtl()`. These use `float`s, `double`s, and `long double`s respectively. In this lab, we will only deal with `float`s for now, and so you should use **`sqrtf()`**. Using other functions may lead to slightly varying results which could impact marking.

Your program should be written in the the `src` directory, inside a file named `ex2q2.c`. The full path is `src/ex2q2.c` (from your working directory).

### Input

Your program should prompt the user for 3 pairs of coordinates in the format `(<float>, <float>)`. You must immediately terminate the program with a non-zero exit code if any invalid input is read in. Again, recall from Part 1's input handling section that valid input is defined as successfully read in input within the required range. The input is guaranteed to fit within a `float` on the lab machine.

### Output

Your program should output all pairs of points that are minimal in distance. The following is the output format:

```
Pa<->Pb: <float>
```

Where `a` and `b` is the number of the point with `a < b`, and `<float>` is the distance between them, rounded to **two decimal places**. You should only print the smallest distance out of all the possible pairs of points. Note that the **distances should be compared before rounding**. If there are multiple pairs that have the same distance, you must print all of them like so:

```
Pa<->Pb: <float>
Px<->Py: <float>
```

Where `a < b`, `x < y`, `a <= x`, and `b <= y`.

If all pairs of points share the same distance, you should output it like so:

```
All points are equal distance: <float>
```

The distance should be formatted to two decimal places. As well, **you must add a comma seperator between the thousands and hundreds digits** (if applicable). This is a requirement of the lab. However, you do not need to add commas for millions and beyond.

### Example I/O

Your program should match the Example I/O **exactly** to obtain marks.

```
Point 1: (10.1, 7.5)
Point 2: (9.1, 10.0)
Point 3: (-4.03, 0.02)

P1<->P2: 2.69
```

```
Point 1: (-9120, 42)
Point 2: (62151.907, -42102.0)
Point 3: (18565.1, 16)

P1<->P3: 27,685.11
```

```
Point 1: (1000, 1000)
Point 2: (0, 0)
Point 3: (-1000, -1000)

P1<->P2: 1,414.21
P2<->P3: 1,414.21
```

```
Point 1: (4.5, 5.33012701892)
Point 2: (2, 1)
Point 3: (7, 1)

All points are equal distance: 5.00
```

```
Point 1: (1, 1)
Point 2: (ten, forty)
```
Note: This input ends the program with a non-zero exit code.

Again, **note the comma between the thousands and hundreds digits**.

## Restrictions
You are only allowed to `#include` the following libraries:

**Part 1:**
- `stdio.h`

**Part 2:**
- `stdio.h`
- `math.h`

Using any other libraries will result in a fail.

## Debugging and using GDB

Unlike Python, C has no convenient error messages that tell you what line a program had an error and why. GDB (GNU Debugger) is a useful tool for detecting errors in your program.

Even if you don't think you need it for this lab, we **highly** recommend you try using it here so you are familiar with it for when you do need it.

To use GDB, you must first compile a debug version of your program by adding the flag `-ggdb` to your usual `gcc` command. This flag ensures the necessary debugging information for `gdb` is available in the final executable.

```bash
gcc -Wall -Werror -std=c99 -ggdb ex2q1.c -o ex2q1.debug
```

Note GDB is only useful for **runtime** errors, and does **not** help detect errors that would stop you from compiling. Your program must successfully compile before using GDB.

Run `gdb ex2q1.debug` (or whatever you named your debug executable). You should now see a new terminal interface, which will allow you to gain some insight into how your program runs. GDB has a number of useful commands, a few of which are listed here. You can and should learn more online.

- `b [line # or function name]` puts a breakpoint at a given location. Running the program will let it "pause" there and you can investigate issues
- `d [breakpoint #]` deletes a specific breakpoint
- `info break` / `i b` gives information about the currently set breakpoints, including breakpoint numbers
- `info stack` / `i s` shows the stack backtrace, indicating which function calls have been made and their arguments. This will be more useful in later labs after learning functions.
- `r`: run the program until a breakpoint or error
- `n`: once a breakpoint has been hit, run the next line of the program. `s` does the same but also steps into functions, which will be useful for later labs, but will also cause errors if used on a built-in function like `printf` or `scanf`.
- `c`: continues execution of the program if pressed after hitting a breakpoint
- `p [variable name]`: prints the current value of a given variable
- `q` quits GDB
- `tui enable` and `tui disable` to toggle a split screen interface where you can view and scroll through your code, as well as interact with GDB commands.

The general workflow will be:

- Set one or more breakpoints where you think the errors are. If you have no idea where the error is, `b main` sets a breakpoint at the very beginning (start of the main function)
- Run the program until the breakpoint. You can add file redirection as usual (ex. `r < input.txt`)
- Execute step by step and print values of questionable variables until you discover the issue

Of course, you can also use a tried and true method of putting `printf` statements everywhere. GDB has the advantage of not modifying your source code, so you do not accidentally leave unwanted `printf`s and mess up the output. In later labs, you may even find that adding `printf`s changes the way some errors show up. In that case, `gdb` is a must for finding the error.

## Checking and Testing

You are provided with a blank check script, `check.sh`, and a validation script `validate.sh`. You will need to fill in `check.sh` with the proper commands to compile your program, execute it using the provided testcases, and then run `diff` checks against the expected output. **Do not modify** `validate.sh`.

You will find the provided testcases in the `Testcases` folder. The input files are named `A-B-input.txt` which you will give to your program via redirection. `A` represents the exercise number, and `B` represents the number of the testcase. **Your program must output to a corresponding file named** `A-B-student.txt` inside the `Testcases` folder. The `A-B-output.txt` file contains the expected output for that testcase. **DO NOT OVERWRITE THIS FILE.**

The steps you must perform inside `check.sh` are outlined below:

1. Compile your program with the **proper compilation flags** `-Wall -Werror -std=c99` along with any other flags required (depending on the lab) such as `-lm`.

2. Execute your programs, utilising input/output redirection to run all the testcases inside the `Testcases` directory. Input redirection allows your program to read from a text file instead of reading your keyboard input. Likewise, output redirection allows your program to output to a text file instead of to the screen. If your program is compiled in `./bin/exAq1`, an example of this then would be:

```bash
./bin/exAq1 < Testcases/1-1-input.txt >| Testcases/1-1-student.txt
```

Recall from Lab 1 that we can use `>|` instead of `>` which ensures that existing output files will be able to be overwritten.

3. Run a `diff`, comparing the expected output and your output to check for any differences. You should use the `-u` flag as shown in Lab 1. For example, to compare your output for the first exercise with the first testcase, you could write:

```bash
diff -u Testcases/1-1-output.txt Testcases/1-1-student.txt
```

Steps 2 and 3 need to be performed for all applicable testcases.

After completing `check.sh`, you can run the `validate.sh` script with the following command:

```bash
./validate.sh
```

If you recieve a permission error, you may have to grant the execute permission by running:

```bash
chmod 700 validate.sh
chmod 700 check.sh
```

Read the output for more details should the check script fail at any point. The `validate.sh` script will execute your `check.sh` and run some additional checks for you as well. `validate.sh` **will not check if your program's output matches the expected output**. That is the responsibility of your `check.sh`.

There is a line `set -e` placed near the top of the `check.sh` for you. **DO NOT REMOVE THIS LINE**. This line will ensure your `check.sh` script terminates if any `diff`s or other commands fail, which the `validate.sh` script will detect and inform you of.

**You are guaranteed a 50% minimum on this lab if all your output matches the expected output.** Ensure your `check.sh` properly compiles, executes, and runs a `diff` on your program's output with the expected output. Remember that `diff` does not have any output if the two compared files are identical.

Important: Make sure all your source code is inside of the source directory `src` and all files are named appropriately (`exAq1.c`, `exAq2.c`, etc. where `A` is the lab number).

## Marking
The marking scheme for this Lab is as follows:

- 50% for Part 1
- 50% for Part 2
- Matching the expected output for all testcases guarantees at least 25% for each part (50% overall). The other 50% will be based on our additional marking cases, which you do not have access to before submission.
- If you do not pass the testcases, you may still pass some of those marking cases and get some marks, so you should submit whatever you have!


//Copyright @CMPUT201 Teaching Team, 2025-2028, not to be disclosed to anyone outside of CMPUT 201 Fall 2025
