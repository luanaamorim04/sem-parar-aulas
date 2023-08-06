#include <iostream>
#define MAXN (int) (2e5 + 10)
#define INF (int) 1e9

using namespace std;

int n, h[MAXN], dp[MAXN], resp[MAXN];

//top down
int f(int idx)
{
	if (idx == 0) return INF;
	if (idx == 1) return 0;
	if (resp[idx] != -1) return resp[idx];

	return resp[idx] = min(f(idx-1)+abs(h[idx-1]-h[idx]), f(idx-2)+abs(h[idx-2]-h[idx]));
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];

	//bottom up
	dp[0] = INF;
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
		dp[i] = min(dp[i-1]+abs(h[i-1]-h[i]), dp[i-2]+abs(h[i-2]-h[i]));

	// cout << dp[n] << endl;

	//top down 
	memset(resp, -1, sizeof resp);
	cout << f(n) << endl;
	return 0;
}