# Homework 1: Design Document

  * author: Haasini Saripella
  * date: April 2026

## introduction

In this homework, I will do the thing and solve important computer science
problems and probably win a
[Turing Award](https://en.wikipedia.org/wiki/Turing_Award) for doing so.

TODO(you): In this homework, I implemented several simple C functions that involve basic
arithmetic, boolean logic, and conditional reasoning. I also wrote a program
called `caat` that processes characters from standard input and modifies vowels
as specified. This assignment helped reinforce function design and multi-file C
program structure.

## function 1: ## function 1: area_of_disk

This function computes the area of a circle using the formula πr². It takes a
radius as input and returns the computed area as a double using the constant
M_PI from `<math.h>`.

## function 2: area_of_ring

This function computes the area of a ring by subtracting the area of the inner
circle from the outer circle. It reuses `area_of_disk` to simplify the
calculation.

## function 3: bigger_minus_smaller

This function compares two integers and returns the difference between the
larger and smaller value. It ensures the result is always non-negative.

## function 4: value_in_range

This function checks whether a given value lies within a closed interval
[lower_bound, upper_bound]. It returns true if the value is inside the range,
and false otherwise.

## function 5: sum_of_greater_squares

This function computes the squares of three numbers, then returns the sum of
the two largest squared values. It ignores the smallest squared value.

## the caat program
The `caat` program reads characters from standard input one at a time using
`getchar()`. It prints each character to standard output using `putchar()`. If
the character is a vowel (a, e, i, o, u in either uppercase or lowercase), it
prints the character twice. The program stops processing input when it reaches
EOF.
