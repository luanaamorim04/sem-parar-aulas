#include <iostream>
#define MAXN (int) (2e5 + 10)
#define INF (int) 1e9

using namespace std;

int n, dp[MAXN][3], a[MAXN], b[MAXN], c[MAXN], k;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i];

	//bottom up
	for (int i = 1; i <= n; i++) // dias
	{
		dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
		dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
		dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
	}

	cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;

	return 0;
}