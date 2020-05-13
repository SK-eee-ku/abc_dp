#  入力
#  足場の高さ
n, k = list(map(int, input().split()))
h = list(map(int, input().split()))


#  方針
#  i番目の足場にいるという状態に対して
#  その足場に最も少ないコストを記録する．

#  A_Frog.pyでわかることだが，pythonはver2のappendを使う方が処理が早い
#  足場0のコストは0
dp = [0]

for i in range(1, n):
    #  i番目の足場のコストの候補
    temp = [dp[j] + abs(h[i] - h[j]) for j in range(i - k, i) if j >= 0]
    #  候補の最小値をコストに記録
    dp.append(min(temp))

print(dp[n - 1])
