#  numpyは偉大
import numpy as np

#  入力
n, w = list(map(int, input().split()))
wv = np.array([list(map(int, input().split(" "))) for _ in range(n)])

#  dpテーブルを0で初期化
#  行:重さの上限(0からwまでのw+1要素)
#  列:使っていい荷物の最大添字(例えば3列目はwv[3]までを使った最適値)
#  i行j列:wv[j]までを使って重さi以下になるようにした時の最大価値
dp = np.zeros((w + 1, n), dtype=np.int)

#  wv[0]だけ別で更新
dp[wv[0, 0] :, 0] = np.full(dp[wv[0, 0] :, 0].shape, wv[0, 1])

#  dpテーブルの完成
for i in range(1, n):
    #  とりあえずwv[i-1]までの最適値をパクる
    dp[:, i] = dp[:, i - 1]
    wNew, vNew = wv[i, 0], wv[i, 1]
    #  i-1列では重さがi-wNewのものにはwv[i]の荷物を詰める選択肢がある．
    #  そこで詰めた結果，最高価値が変わるのかを確認する．
    dp[wNew:, i] = np.fmax(dp[wNew:, i - 1], vNew + dp[:-wNew, i - 1])

print(dp[w, n - 1])
