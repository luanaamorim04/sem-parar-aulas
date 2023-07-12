#include <iostream>
#include <queue>
#include <deque>
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9 + 10)
#define ii pair<int, int> 
#define iii tuple<int, int, int>

using namespace std;

int n, m, a, b, vis[MAXN];
vector<int> grafo[MAXN];

void dfs(int u)
{
	vis[u] = 1;
	for (int v : grafo[u])
	{
		if (vis[v]) continue;
		dfs(v);
	}
}

int32_t main()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	dfs(1);
}