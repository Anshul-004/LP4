#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n) {
  int drow = row;
  int dcol = col;

  // Check upper-left diagonal
  while (row >= 0 && col >= 0) {
    if (board[row][col] == 'Q')
      return false;
    row--;
    col--;
  }

  // Check left row
  row = drow;
  col = dcol;
  while (col >= 0) {
    if (board[row][col] == 'Q')
      return false;
    col--;
  }

  // Check lower-left diagonal
  row = drow;
  col = dcol;
  while (row < n && col >= 0) {
    if (board[row][col] == 'Q')
      return false;
    row++;
    col--;
  }

  return true;
}

void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans) {
  if (col == n) {
    ans.push_back(board);
    return;
  }

  for (int row = 0; row < n; row++) {
    if (isSafe(row, col, board, n)) {
      board[row][col] = 'Q';
      solve(col + 1, n, board, ans);
      board[row][col] = '.';
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<vector<string>> ans;
  vector<string> board(n, string(n, '.'));

  solve(0, n, board, ans);

  for (auto solution : ans) {
    for (auto row : solution)
      cout << row << endl;
    cout << endl;
  }

  return 0;
}
