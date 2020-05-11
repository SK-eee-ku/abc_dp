#include <iomanip>
#include <iostream>

using namespace std;

double solver(int i, int j, int k, double ***dp, int n) {
  if (dp[i][j][k] >= 0)
    return dp[i][j][k];
  if (i == 0 and j == 0 and k == 0)
    return 0;

  double ret = 0.0;
  if (i > 0)
    ret += solver(i - 1, j, k, dp, n) * i;
  if (j > 0 and i < n)
    ret += solver(i + 1, j - 1, k, dp, n) * j;
  if (k > 0 and j < n)
    ret += solver(i, j + 1, k - 1, dp, n) * k;

  ret += static_cast<double>(n);
  ret *= 1.0 / (i + j + k);
  return dp[i][j][k] = ret;
}

int main(int argc, char const *argv[]) {

  int n;
  cin >> n;
  int a[3] = {0};
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    a[(temp - 1) % 3]++;
  }

  double ***dp = new double **[n + 1];
  for (int i = 0; i <= n; i++)
    dp[i] = new double *[n + 1];

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      dp[i][j] = new double[n + 1];

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++)
        dp[i][j][k] = -1.0;

  dp[0][0][0] = 0.0;

  double ans = solver(a[0], a[1], a[2], dp, n);
  cout << setprecision(10) << ans << endl;

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      delete[] dp[i][j];

  for (int i = 0; i <= n; i++)
    delete[] dp[i];

  delete[] dp;

  return 0;
}
