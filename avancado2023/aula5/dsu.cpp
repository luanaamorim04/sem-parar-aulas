#include <iostream>
#include <vector>
#include <set>
#define MAXN (int) (2e5 + 10)

using namespace std;

int n, m, a, b, pai[MAXN], tam[MAXN];
vector<pair<int, int> > arestas;

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
		cin >> a >> b;
		arestas.push_back({a, b});
	}

	for (int i = 1; i <= n; i++)
		pai[i] = i, tam[i] = 1;

	for (auto[a, b] : arestas)
		if (find(a) != find(b)) join(a, b);

	set<int> cj;
	for (int i = 1; i <= n; i++)
		cj.insert(find(i)); // log**2

	cout << cj.size()-1 << endl;
	for (auto u : cj)
	{
		if (u == *(cj).begin()) continue;
		cout << *(cj).begin() << ' ' << u << endl;
	}

}



