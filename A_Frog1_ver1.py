#  入力
#  足場の高さ
input()
h = list(map(int, input().split()))


#  方針
#  i番目の足場にいるという状態に対して
#  その足場に最も少ないコストを記録する．

#  初期化は大きは数で 1e20は適当
dp = [1e20 for i in range(len(h))]
#  スタートはコスト0
dp[0] = 0

#  i番目の足場でのコストを利用して
#  i+1, i+2番目のコストを計算する
for i in range(len(h) - 1):
    dp[i + 1] = (
        dp[i + 1]
        if dp[i + 1] < dp[i] + abs(h[i + 1] - h[i])
        else dp[i] + abs(h[i + 1] - h[i])
    )
    if i + 2 < len(h):
        dp[i + 2] = (
            dp[i + 2]
            if dp[i + 2] < dp[i] + abs(h[i + 2] - h[i])
            else dp[i] + abs(h[i + 2] - h[i])
        )

print(dp[len(h) - 1])
