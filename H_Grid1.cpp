#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mod = 1e9 + 7;

int rec(int r, int c, string *maze, int **dp, int h, int w) {
  if (r == h - 1 and c == w - 1)
    return dp[r][c] = 1;

  if (r == h or c == w)
    return 0;

  if (dp[r][c] != -1)
    return dp[r][c];

  if (maze[r][c] == '#')
    return dp[r][c] = 0;

  int temp =
      (rec(r + 1, c, maze, dp, h, w) + rec(r, c + 1, maze, dp, h, w)) % mod;
  return dp[r][c] = temp;
}

int main(int argc, char const *argv[]) {

  int h, w;
  cin >> h >> w;
  string *maze = new string[h];
  for (int i = 0; i < h; i++) {
    cin >> maze[i];
  }

  int **dp = new int *[h];
  for (int i = 0; i < h; i++) {
    dp[i] = new int[w];
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      dp[i][j] = -1;
    }
  }

  cout << rec(0, 0, maze, dp, h, w) << endl;

  for (int i = 0; i < h; i++) {
    delete[] dp[i];
  }
  delete[] dp;
  return 0;
}
