#include <iostream>
#include <vector>
#include <set>
#define MAXN (int) (2e5 + 10)

using namespace std;

int n, m, a, b, c, pai[MAXN], tam[MAXN];
vector<tuple<int, int, int> > arestas;

int find(int x)
{
	if (x == pai[x]) return x;
	return find(pai[x]);
}

void join(int u, int v)
{
	int pu = find(u), pv = find(v);
	if (tam[pu] > tam[pv]) pai[pv] = pu, tam[pu] += tam[pv];
	else pai[pu] = pv, tam[pv] += tam[pu]; 
}

int main()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		arestas.push_back({c, a, b});
	}

	sort(arestas.begin(), arestas.end());


	int soma = 0;
	for (int i = 1; i <= n; i++)
		pai[i] = i, tam[i] = 1;

	for (auto[c, a, b] : arestas)
	{
		if (find(a) == find(b)) continue;
		join(a, b);
		soma += c;
	}

	cout << soma << endl;
}



