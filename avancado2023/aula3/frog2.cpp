#include <iostream>
#define MAXN (int) (2e5 + 10)
#define INF (int) 1e9

using namespace std;

int n, h[MAXN], dp[MAXN], resp[MAXN], k;

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> h[i];

	//bottom up
	for (int i = 0; i <= n; i++)
		dp[i] = INF;

	dp[1] = 0; // caso base
	for (int i = 2; i <= n; i++) // posição atual (estado da dp)
		for (int j = 1; j <= min(i, k); j++) // transição (tam do pulo)
			dp[i] = min(dp[i], dp[i-j]+abs(h[i-j]-h[i])); // menor resposta para k pulos

	cout << dp[n] << endl;

	return 0;
}