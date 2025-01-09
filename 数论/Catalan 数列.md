## 〇、概要

操作 1 和操作 2 分别执行 n 次，
其中每个时刻执行操作 2 的次数不得超过执行操作 1 的次数，
总方案数称为 Catalan 数。

## 一、Dp 实现

```c++
int Catalan(int n)
{
	vector<vector<int64_t>> dp(n + 1, vector<int64_t>(n + 1));
    for (int i = 0; i<= n; ++i)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n][n];
}
```

## 二、结论
```c++
int Catalan(int n)
{
    // return C(2 * n, n) / (n + 1);
	// return C(2 * n, n) - C(2 * n, n - 1);
	// return Catalan(n - 1) * (4 * n - 2) / (n + 1);
}
```