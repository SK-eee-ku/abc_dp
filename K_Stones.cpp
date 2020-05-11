#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  int *a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  bool *dp = new bool[k + 1];
  for (int i = 0; i < k; i++) {
    dp[i] = false;
  }


  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < n; j++) {
      if (i - a[j] >= 0)
        dp[i] |= !dp[i - a[j]];
    }
  }

  if (dp[k])
    cout << "First" << endl;
  else
    cout << "Second" << endl;

  delete[] dp;
  delete[] a;
  return 0;
}
