#include <iostream>
#include <vector>
using namespace std;

const int N = 9;

bool isSafe(const vector<vector<int>>& mat, int row, int col, int num) {
  for (int x = 0; x < N; x++) {
    if (mat[row][x] == num || mat[x][col] == num)
      return false;
  }

  int startRow = row - row % 3;
  int startCol = col - col % 3;

  for (int i = startRow; i < startRow + 3; i++) {
    for (int j = startCol; j < startCol + 3; j++) {
      if (mat[i][j] == num)
        return false;
    }
  }

  return true;
}

bool solveSudoku(vector<vector<int>>& mat) {
  for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
      if (mat[row][col] == 0) {  // Empty cell
        for (int num = 1; num <= 9; num++) {
          if (isSafe(mat, row, col, num)) {
            mat[row][col] = num;
            if (solveSudoku(mat))
              return true;
            mat[row][col] = 0;  // Backtrack
          }
        }
        return false;  // No valid number found
      }
    }
  }
  return true;  // Solved
}

void printSudoku(const vector<vector<int>>& mat) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << mat[i][j] << " ";
    }
    cout << "\n";
  }
}

int main() {
  vector<vector<int>> mat = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
  };

  if (solveSudoku(mat)) {
    cout << "Solved Sudoku:\n";
    printSudoku(mat);
  } else {
    cout << "No solution exists\n";
  }

  return 0;
}
