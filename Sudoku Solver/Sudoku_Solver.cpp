#include <iostream>
using namespace std;

const int SIZE = 9;

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if number exists in the row
bool isRowSafe(int grid[SIZE][SIZE], int row, int num)
{
    for (int col = 0; col < SIZE; col++)
    {
        if (grid[row][col] == num)
            return false;
    }
    return true;
}

// Check if number exists in the column
bool isColSafe(int grid[SIZE][SIZE], int col, int num)
{
    for (int row = 0; row < SIZE; row++)
    {
        if (grid[row][col] == num)
            return false;
    }
    return true;
}

// Check 3x3 subgrid
bool isBoxSafe(int grid[SIZE][SIZE], int startRow, int startCol, int num)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[startRow + i][startCol + j] == num)
                return false;
        }
    }
    return true;
}

// Check if placing number is valid
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num)
{
    return isRowSafe(grid, row, num) &&
           isColSafe(grid, col, num) &&
           isBoxSafe(grid, row - row % 3, col - col % 3, num);
}

// Solve Sudoku using Backtracking
bool solveSudoku(int grid[SIZE][SIZE])
{
    int row, col;
    bool emptyFound = false;

    // Find an empty cell
    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {
            if (grid[row][col] == 0)
            {
                emptyFound = true;
                goto FOUND;
            }
        }
    }

FOUND:

    // If no empty cell found, Sudoku solved
    if (!emptyFound)
        return true;

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            // Backtrack
            grid[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int grid[9][9] =
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    cout << "Original Sudoku:\n\n";
    printGrid(grid);

    if (solveSudoku(grid))
    {
        cout << "\nSolved Sudoku:\n\n";
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists.";
    }

    return 0;
}