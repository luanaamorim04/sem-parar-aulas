#include <iostream>
#include <vector>
#include <queue>
#define MAXN (int) (1e5 + 10)

using namespace std;

vector<int> grafo[MAXN];
queue<int> fila;
vector<pair<int, int> > arestas;
int n, m, a, b, vis[MAXN], comp, last;

int main()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		if (i != 1) 
			arestas.push_back({last, i});
		last = i;
		comp++;
		//bfs
		fila.push(i);
		while (!fila.empty())
		{
			int u = fila.front(); fila.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			for (int v : grafo[u])
				if (!vis[v]) fila.push(v);
		}
	}

	cout << comp - 1 << endl;
	for (auto[a, b] : arestas)
		cout << a << ' ' << b << endl;


}
