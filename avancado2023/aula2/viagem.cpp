#include <bits/stdc++.h>
#define MAXN (int) (2e4 + 10)
#define MAXV 200 + 5
#define INF (int) (1e9 + 10)
#define ii pair<int, int> 
#define iii tuple<int, int, int>

using namespace std;

priority_queue<iii, vector<iii>, greater<iii> > pq;
int n, m, a, b, t, p, v, dist[MAXN][MAXV];
vector<iii> grafo[MAXN];

int32_t main()
{
	cin >> v >> n >> m;
	while (m--)	
	{
		cin >> a >> b >> t >> p;
		grafo[a].push_back({b, t, p});
		grafo[b].push_back({a, t, p});
	}

	cin >> a >> b;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < MAXV; j++)
			dist[i][j] = INF;

	dist[a][0] = 0;
	pq.push({0, a, 0}); // {tempo, vertice, custo}
	while (!pq.empty())
	{
		auto[t, u, c] = pq.top(); pq.pop();
		if (t > dist[u][c] || c > v) continue;
		for (auto[v, tempo, custo] : grafo[u])
		{
			if (dist[v][custo + c] > dist[u][c] + tempo)
			{
				dist[v][custo + c] = dist[u][c] + tempo;
				pq.push({dist[v][custo + c], v, custo + c});
			}
		}
	}

	int resp = INF;
	for (int i = 0; i <= v; i++)
		resp = min(resp, dist[b][i]);

	cout << (resp == INF ? -1 : resp) << endl;
}




