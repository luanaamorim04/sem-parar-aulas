#include <iostream>
#include <queue>
#include <deque>
#include <priority_queue>
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9 + 10)
#define ii pair<int, int> 
#define iii tuple<int, int, int>

using namespace std;

priority_queue<ii, vector<ii>, greater<ii> > pq;
int n, m, a, b, dist[MAXN];
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

	cin >> a >> b;

	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	dist[a] = 0;
	pq.push({0, a});
	while (!pq.empty())
	{
		auto[d, u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;
		for (auto[v, w] : grafo[u])
		{
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}

	cout << dist[b] << endl;
}




