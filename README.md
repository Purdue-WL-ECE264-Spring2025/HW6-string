# HW6: String Manipulation Assignment
Deadline: 02/28/2025 

Late Due Date: 03/05/2025

## Goals
- Practice using `malloc` and pointers.
- Understand how to manage memory for strings (including the null terminator).
- Work with structs to encapsulate data.

## Overview
In this assignment, you will implement a series of functions focused on string manipulation and dynamic memory allocation in C. The primary goal is to provide hands-on practice with `malloc`, working with `structs`, and understanding how to manage memory when handling strings. You'll start with simple tasks like copying strings and gradually move on to more complex operations like joining and splitting strings, which require thoughtful memory management and struct usage.

## Tasks
### 1. Copy String
**Function**: `char* copy_string(const char* source)`
- **Description**: Create a copy of the input string `source` using `malloc`. Do not use `strlen` and `strcpy`; manually copy each character, including the null terminator.

- **Parameters**:
  - `source`: The string to copy (may be empty or `NULL`).

- **Returns**:
  - A newly allocated copy of `source`.
  - If `source` is `NULL`, return `NULL`.

### 2. Join Strings
**Function**: `char* join_strings(const char* const* strings, size_t num_strings, const char* separator)`
- **Description**: Combine an array of strings into a single string, with each substring separated by the `separator`.

- **Parameters**:
    - `strings`: A pointer to an array of strings. Each element in the array is a string that will be joined.
    - `num_strings`: The number of strings in the strings array.
    - `separator`: A string that will be inserted between each pair of adjacent strings.

- **Returns**:
  - The joined string. If the input array is empty, return an empty string.

### 3. Split String
**Function**: `struct Strings split_string(char const* text, char separator)`
- **Description**: 
Split a string into substrings based on occurrences of the specified separator character. It returns a `Strings` structure containing an array of dynamically allocated substrings and the number of substrings.

- **Parameters**:
    - `text`: A pointer to a string that needs to be split.
    -  `separator`: A character (char) that serves as the delimiter for splitting the string.

- **Returns**:
    - A `Strings` structure.
    - If `text` an empty string, the function should return an empty `Strings` structure.

## What to submit?

Please submit ONLY the `str.c` and `str.h` to Gradescope.