#  入力
#  足場の高さ
input()
h = list(map(int, input().split()))


#  方針
#  i番目の足場にいるという状態に対して
#  その足場に最も少ないコストを記録する．

#  スタートはコスト0
dp = [0]

#  i番目の足場でのコストを
#  i-1, i-2番目のコストを利用して計算する
#  1番目は手動で更新した方がコードが簡単になる．
dp.append(dp[0] + abs(h[1] - h[0]))

for i in range(2, len(h)):
    dp.append(min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2])))

print(dp[len(h) - 1])
