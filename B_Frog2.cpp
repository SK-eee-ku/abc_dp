#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  int *h = new int[n];
  int *dp = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    dp[i] = 0;
  }

  for (int i = 1; i < n; i++) {
    int temp = INT32_MAX;
    for (int j = 1; j <= k and i - j >= 0; j++) {
      temp = (dp[i - j] + abs(h[i] - h[i - j])) < temp
                 ? (dp[i - j] + abs(h[i] - h[i - j]))
                 : temp;
    }
    dp[i] = temp;
  }

  cout << dp[n - 1] << endl;
  delete[] h;
  delete[] dp;
  return 0;
}
