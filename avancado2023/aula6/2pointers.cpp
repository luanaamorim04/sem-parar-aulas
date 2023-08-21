#include <bits/stdc++.h>
// #include <iostream>
// #include <map>
#define MAXN (int) (2e5 + 10)
#define ii pair<int, int> 

using namespace std;

ii resp;
int n, m;
ii arr[MAXN];

int solve()
{
	int l = 1, r = n;
	while (l < r)
	{
		if (arr[l].first+arr[r].first < m)
			l++;

		if (arr[l].first+arr[r].first > m)
			r--;

		if (arr[l].first+arr[r].first == m)
		{
			resp.first = arr[l].second;
			resp.second = arr[r].second;
			return 1;
		}
	}

	return 0;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i;
	}

	sort(arr+1, arr+n+1); //nlog

	if (solve())
		cout << min(resp.second, resp.first) << ' ' << max(resp.first, resp.second) << endl;
	else 
		cout << "IMPOSSIBLE" << endl;
}