# Arbitrary Precision Calculator

Name: Sharanu

## Description

This is an Arbitrary Precision Calculator project written in C.

It uses doubly linked lists to store the digits of large numbers.

## Operations

1. Addition (+)
2. Subtraction (-)
3. Multiplication (x / X)
4. Division (/)

## Files

main.c - Main program

input.c - Creates the linked list

addition.c - Performs addition

subtraction.c - Performs subtraction

multiplication.c - Performs multiplication

division.c - Performs division

apc.h - Contains structure and function declarations

Makefile - Used to compile the project

## How to Compile

make

## How to Run

./apc number1 operator number2

Examples:

./apc 123 + 456

Result: 579

./apc 123 x 45

Result: 5535

./apc 123 / 3

Result: 41

## Clean

make clean