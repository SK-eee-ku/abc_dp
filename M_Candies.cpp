#include <iostream>

using namespace std;

int mod = 1e9 + 7;

int main(int argc, char const *argv[]) {

  int n, k;
  cin >> n >> k;
  int *a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long **dp = new long *[n + 1];
  for (int i = 0; i <= n; i++)
    dp[i] = new long[k + 1];

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= k; j++)
      dp[i][j] = -1;

  dp[0][0]=1;









  for (int i = 0; i <= n; i++)
    delete[] dp[i];
  delete[] dp;

  delete[] a;
  return 0;
}
