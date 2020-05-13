#  入力
n = int(input())
abcList = []
for i in range(n):
    abcList.append(list(map(int, input().split())))


#  dpテーブルの初期化
dp = [abcList[0]]

#  dpテーブルの完成
for i in range(1, n):
    dp.append(
        [
            abcList[i][0] + max(dp[-1][1], dp[-1][2]),
            abcList[i][1] + max(dp[-1][2], dp[-1][0]),
            abcList[i][2] + max(dp[-1][0], dp[-1][1]),
        ]
    )

print(max(dp[-1]))
