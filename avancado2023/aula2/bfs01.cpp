#include <iostream>
#include <queue>
#include <deque>
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9 + 10)
#define ii pair<int, int> 
#define iii tuple<int, int, int>

using namespace std;

int n, m, a, b, c, dist[MAXN];
vector<ii> grafo[MAXN];

int32_t main()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
		grafo[b].push_back({a, c});
	}

	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	deque<ii> fila;
	fila.push_front({1, 0});
	dist[1] = 0;
	while (!fila.empty())
	{
		auto[u, d] = fila.front(); fila.pop_front();
		if (d > dist[u]) continue;
		for (auto[v, w] : grafo[u])
		{
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				if (w == 1) fila.push_back({v, dist[v]});
				else fila.push_front({v, dist[v]});
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dist[i] << ' ';
	cout << endl;
}




