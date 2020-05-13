#  numpyの力を借りて時間短縮を狙う
import numpy as np

#  入力
n, k = list(map(int, input().split()))
h = np.array(list(map(int, input().split())))

#  方針
#  i番目の足場にいるという状態に対して
#  その足場に最も少ないコストを記録する．

dp = np.zeros(n, dtype=np.int)
for i in range(1, n):
    st = max(0, i - k)
    dp[i] = np.min(dp[st:i] + np.abs(h[i] - h[st:i]))

print(dp[-1])
