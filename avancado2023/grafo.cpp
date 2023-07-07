#include <iostream>
#include <vector>
#include <queue>
#define MAXN 1000

using namespace std;

vector<int> grafo[MAXN];
queue<int> fila;
int n, m, a, b;

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
		cout << i << endl;
		for (int u : grafo[i])
			cout << u << ' ';
		cout << endl;
	}


}
