
n = int(input())
stairs = []

for i in range(n):
    a = int(input())
    stairs.append(a)

if n == 1:
    print(stairs[0])
else:
    dp = [[0] * n, [0] * n]
    dp[0][0] = stairs[0]
    dp[1][0] = stairs[0]
    dp[0][1] = stairs[0] + stairs[1]
    dp[1][1] = stairs[1]

    for i in range(2, n):
        dp[1][i] = max(dp[0][i - 2], dp[1][i - 2]) + stairs[i]
        dp[0][i] = dp[1][i - 1] + stairs[i]

    print(max(dp[0][n - 1], dp[1][n - 1]))