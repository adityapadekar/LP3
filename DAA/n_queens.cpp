#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <functional>
using namespace std;

vector<vector<string>> solveNQueens(int n, int first_queen_col) {
    set<int> col;
    set<int> posDiag;
    set<int> negDiag;
    
    vector<vector<string>> res;
    vector<vector<string>> board(n, vector<string>(n, "."));
    
    std::function<void(int)> backtrack;
    backtrack = [&](int r) {
        if (r == n) {
            vector<string> solution;
            for (const auto& row : board) {
                string rowStr;
                for (const auto& cell : row) {
                    rowStr += cell;
                }
                solution.push_back(rowStr);
            }
            res.push_back(solution);
            return;
        }
        
        for (int c = 0; c < n; c++) {
            if (col.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) {
                continue;
            }
            
            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            board[r][c] = "Q";
            
            backtrack(r + 1);
            
            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = ".";
        }
    };
    
    col.insert(first_queen_col);
    posDiag.insert(0 + first_queen_col);
    negDiag.insert(0 - first_queen_col);
    board[0][first_queen_col] = "Q";
    
    backtrack(1);
    return res;
}

int main() {
    int n = 8;
    int first_queen_col = 1;
    
    vector<vector<string>> solutions = solveNQueens(n, first_queen_col);
    for (const string& row : solutions[0]) {
        for (int i = 0; i < row.length(); i++) {
            cout << row[i];
            if (i < row.length() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}