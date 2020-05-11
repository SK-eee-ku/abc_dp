#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<vector<int>> w;
  for (int i = 0; i < n; i++) {
    vector<int> temp;
    for (int j = 0; j < 3; j++) {
      int k;
      cin >> k;
      temp.push_back(k);
    }
    w.push_back(temp);
  }

  vector<vector<int>> dp;
  pair<int, int> temp(0, 0);

  dp.push_back(w[0]);

  for (int i = 1; i < n; i++) {
    vector<int> temp;

    for (int j = 0; j < 3; j++) {
      temp.push_back(w[i][j] + (dp[i - 1][(j + 1) % 3] > dp[i - 1][(j + 2) % 3]
                                    ? dp[i - 1][(j + 1) % 3]
                                    : dp[i - 1][(j + 2) % 3]));
    }

    dp.push_back(temp);
  }

  int ans = dp[n - 1][0];
  for (int i = 1; i < 3; i++) {
    ans = ans > dp[n - 1][i] ? ans : dp[n - 1][i];
  }

  cout << ans << endl;

  return 0;
}
