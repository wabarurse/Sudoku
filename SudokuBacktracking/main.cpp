//
//  main.cpp
//  Sudoku
//
//  Created by Richard Huang on 2024-07-26.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sudBoard {{8, 5, 6, 0, 0, 2, 0, 0, 1},
                              {0, 9, 0, 0, 0, 0, 0, 0, 5},
                              {4, 0, 0, 3, 6, 0, 2, 0, 0},
                              {3, 0, 0, 1, 9, 0, 0, 0, 0},
                              {0, 2, 9, 5, 0, 7, 1, 4, 0},
                              {0, 0, 0, 0, 2, 3, 0, 0, 7},
                              {0, 0, 8, 0, 4, 1, 0, 0, 2},
                              {7, 0, 0, 0, 0, 0, 0, 9, 0},
                              {5, 0, 0, 7, 0, 0, 8, 1, 6}};

bool isValidNum(vector<vector<int>> board, int r, int c, int val) {
    for (int i = 0; i < 9; ++i) {
        if (board[r][i] == val || board[i][c] == val) {
            return false;
        }
    }

    int startRow = (r / 3) * 3;
    int startCol = (c / 3) * 3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[startRow + i][startCol + j] == val) {
                return false;
            }
        }
    }

    return true;
}

bool solve(vector<vector<int>> &board, int r, int c) {
    if(r == 9) {
        return true;
    } else if(c == 9) {
        return solve(board, r + 1, 0);
    } else if(board[r][c] != 0) {
        return solve(board, r, c + 1);
    } else {
        for (int i = 1; i < 10; i++) {
            if(isValidNum(board, r, c, i)) {
                board[r][c] = i;
                if (solve(board, r, c + 1)) {
                    return true;
                }
                board[r][c] = 0;
            }

        }
        return false;
    }
}

void printBoard(vector<vector<int>> board) {
    for(auto vec : board) {
        for(auto v : vec) {
            cout << v << " ";
        }
        cout << '\n';
    }
}

int main() {
    printBoard(sudBoard);
    solve(sudBoard, 0, 0);
    cout << '\n';
    printBoard(sudBoard);
    //DONE
}


