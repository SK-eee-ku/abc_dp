#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int N, W;
  cin >> N >> W;
  vector<int> w;
  vector<int> v;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    w.push_back(a);
    v.push_back(b);
  }

  long **dp = new long *[N + 1];
  for (int i = 0; i <= N; i++) {
    dp[i] = new long[W + 1];
  }

  for (int i = 0; i <= W; i++) {
    dp[0][i] = 0;
  }

  for (int i = 1; i <= N; i++) {
    dp[i][0] = 0;
    for (int j = 1; j <= W; j++) {
      long temp = dp[i][j - 1] > dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j];

      if (j - w[i-1] >= 0)
        if (dp[i - 1][j - w[i-1]] + v[i-1] > temp)
          temp = dp[i - 1][j - w[i-1]] + v[i-1];

      dp[i][j] = temp;
    }
  }

  cout << dp[N][W] << endl;

  for (int i = 0; i <= N; i++) {
    delete[] dp[i];
  }
  delete[] dp;

  return 0;
}
