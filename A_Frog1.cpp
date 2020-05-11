#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int *h = new int[n];
  int *dp = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    dp[i] = 0;
  }

  dp[1] = abs(h[0] - h[1]);
  for (int i = 2; i < n; i++) {
    dp[i] =
        (dp[i - 1] + abs(h[i] - h[i - 1])) < (dp[i - 2] + abs(h[i] - h[i - 2]))
            ? (dp[i - 1] + abs(h[i] - h[i - 1]))
            : (dp[i - 2] + abs(h[i] - h[i - 2]));
  }

  cout << dp[n - 1] << endl;
  delete[] h;
  delete[] dp;
  return 0;
}
