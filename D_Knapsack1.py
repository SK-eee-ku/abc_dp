import numpy as np

#  n, w = list(map(int, input().split()))
#  wv = np.array([list(map(int, input().split())) for i in range(n)])
n, w = 3, 8
wv = np.array([[3, 30], [4, 50], [5, 60]])

dp = np.zeros((w + 1, n), dtype=np.int)
dp[w[0, 0] :, 0] = np.full(dp[w[0, 0] :, 0].shape, w[0, 1])
for i in range(1, n):
    dp[:, i] = dp[:, i - 1]
    wNew, vNew = wv[i, 0], wv[i, 1]
    dp[wNew:, :] = np.fmax(dp[wNew:, :], vNew + dp[:-wNew, :])

print(dp[w, n - 1])
