
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  int n;
  cin >> n;
  double *p = new double[n];
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  double **dp = new double *[n + 1];
  for (int i = 0; i <= n; i++) {
    dp[i] = new double[n + 1];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = 0;
    }
  }

  dp[0][0] = 1.0;
  for (int i = 0; i < n; i++) {
    dp[i + 1][0] = dp[i][0] * (1.0 - p[i]);
    for (int j = 0; j < n; j++) {
      dp[i + 1][j + 1] = dp[i][j + 1] * (1.0 - p[i]) + dp[i][j] * p[i];
    }
  }

  double ans = 0.0;
  for (int i = (n + 1) / 2; i <= n; i++) {
    ans += dp[n][i];
  }

  cout << setprecision(10) << ans << endl;

  for (int i = 0; i <= n; i++) {
    delete[] dp[i];
  }
  delete[] dp;
  return 0;
}
