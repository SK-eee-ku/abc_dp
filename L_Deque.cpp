#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  int n;
  cin >> n;
  int *a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long **dp = new long *[n + 1];
  for (int i = 0; i <= n; i++) {
    dp[i] = new long[n + 1];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = 0;
      // if (i == j)
      //   dp[i][j] = 0;
      // else
      //   dp[i][j] = -1;
    }
  }

  for (int len = 1; len <= n; len++) {
    for (int i = 0; i + len <= n; i++) {
      int j = i + len;
      if ((n - len) % 2 == 0)
        dp[i][j] = (dp[i + 1][j] + a[i]) > (dp[i][j - 1] + a[j - 1])
                       ? (dp[i + 1][j] + a[i])
                       : (dp[i][j - 1] + a[j - 1]);
      else
        dp[i][j] = (dp[i + 1][j] - a[i]) < (dp[i][j - 1] - a[j - 1])
                       ? (dp[i + 1][j] - a[i])
                       : (dp[i][j - 1] - a[j - 1]);
    }
  }

  cout << dp[0][n] << endl;

  for (int i = 0; i < n; i++) {
    delete[] dp[i];
  }
  delete[] dp;
  delete[] a;
  return 0;
}
