#include <bits/stdc++.h>

class EightQueensSolver {
private:
    const int BOARD_SIZE = 8;
    int placedRow;
    int placedCol;
    std::vector<std::vector<char>> board;

    bool isSafe(int row, int col) {
        for (int i{}; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        for (int i{ row }, j{ col }; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i{ row }, j{ col }; i >= 0 && j < BOARD_SIZE; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    bool solveUtil(int row) {
        if (row == BOARD_SIZE) return true;

        if (row == placedRow) {
            if (isSafe(placedRow, placedCol)) {
                board[placedRow][placedCol] = 'Q';
                return solveUtil(row + 1);
            }

            return false;
        }

        for (int i{}; i < BOARD_SIZE; i++) {
            if (isSafe(row, i)) {
                board[row][i] = 'Q';

                if (solveUtil(row + 1)) return true;

                board[row][i] = '.';
            }
        }

        return false;
    }

public:
    EightQueensSolver() {
        board.resize(BOARD_SIZE, std::vector<char>(BOARD_SIZE, '.'));
    }


    bool  solve(int row, int col) {
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            std::cout << "Invalid first queen position!" << std::endl;
            return false;
        }

        placedRow = row;
        placedCol = col;

        return solveUtil(0);
    }

    void printSolution() {
        std::cout << "8-Queens Solution:\n";
        for (const auto& row : board) {
            for (char cell : row) {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    EightQueensSolver solver;

    if (solver.solve(3, 3)) {
        solver.printSolution();
    }
    else {
        std::cout << "Solution does not exist!" << std::endl;
    }

    return 0;
}
