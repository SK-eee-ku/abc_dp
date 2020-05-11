#include <iomanip>
#include <iostream>
#include <limits.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {

  int N, W;
  cin >> N >> W;
  vector<int> w;
  vector<int> v;
  long V = 0;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    w.push_back(a);
    v.push_back(b);
    V += b;
  }

  long **dp = new long *[N + 1];
  for (int i = 0; i <= N; i++) {
    dp[i] = new long[V + 1];
  }

  for (int i = 0; i <= N; i++) {
    for (long j = 0; j <= V; j++) {
      dp[i][j] = LONG_MAX - 1e9;
    }
  }
  dp[0][0] = 0;

  for (int i = 0; i < N; i++) {
    for (long j = 0; j <= V; j++) {
      long temp = dp[i][j];
      if (j - v[i] >= 0)
        temp =
            temp < (w[i] + dp[i][j - v[i]]) ? temp : (w[i] + dp[i][j - v[i]]);
      dp[i + 1][j] = temp < dp[i + 1][j] ? temp : dp[i + 1][j];
    }
  }

  long ans = 0;
  for (long i = 0; i <= V; i++) {
    if (W >= dp[N][i])
      ans = i;
  }
  cout << ans << endl;

  for (int i = 0; i <= N; i++) {
    delete[] dp[i];
  }
  delete[] dp;

  return 0;
}
