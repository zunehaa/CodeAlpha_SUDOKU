# CodeAlpha_SUDOKU
This is a console-based Sudoku Solver built using C++, which uses backtracking to solve any valid Sudoku puzzle. You can input an incomplete 9x9 grid, and it will either solve it or inform you if a solution doesn’t exist.

# 🧩 Sudoku Solver in C++

This is a simple and efficient Sudoku Solver built using C++. The program takes an incomplete 9x9 Sudoku grid as input and uses **backtracking** to solve it.

## 📌 Features
- Solves any valid 9x9 Sudoku puzzle
- Uses backtracking algorithm
- Validates number placement
- Easy to customize and extend

## 🛠️ How It Works
The algorithm checks each empty cell in the grid and tries numbers from 1 to 9. It proceeds recursively, backtracking when a number doesn’t lead to a valid solution, until the entire grid is filled.

## 🧮 Example Input
0 0 0 2 6 0 7 0 1 <br>
6 8 0 0 7 0 0 9 0 <br>
1 9 0 0 0 4 5 0 0 <br>
8 2 0 1 0 0 0 4 0 <br>
0 0 4 6 0 2 9 0 0 <br>
0 5 0 0 0 3 0 2 8 <br>
0 0 9 3 0 0 0 7 4 <br>
0 4 0 0 5 0 0 3 6 <br>
7 0 3 0 1 8 0 0 0 <br>


## How_to_run:
  steps:
    - Step 1: Download or clone the repository
    - Step 2: Make sure you have a C++ compiler installed (e.g., g++)
    - Step 3: Compile the program using the terminal:
        command: g++ -o sudoku_solver sudoku_solver.cpp
    - Step 4: Run the compiled program:
        command: ./sudoku_solver
    - Step 5: Enter the Sudoku puzzle manually or edit the hardcoded grid in the code

## Algorithm_used:
  name: Backtracking
  explanation: |
    - The algorithm tries placing numbers 1 through 9 in each empty cell.
    - It checks whether placing the number maintains the Sudoku rules:
        - No repetition in the row
        - No repetition in the column
        - No repetition in the 3x3 subgrid
    - If valid, it proceeds to the next cell recursively.
    - If no valid number is found, it backtracks to the previous cell and tries a different number.

## Features:
  - Solves any standard 9x9 Sudoku puzzle
  - Fast and memory-efficient
  - Easy to understand and modify
  - Written in clean, modern C++
