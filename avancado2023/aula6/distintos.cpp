// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#define MAXN (int) (2e5 + 10)
#define ii pair<int, int> 

using namespace std;

int n, m, arr[MAXN], freq[MAXN];

int solve()
{
	int l = 1, resp = 0;
	for (int r = 1; r <= n; r++) // r
	{
		freq[arr[r]]++;
		while (freq[arr[r]] > 1) // l
		{
			freq[arr[l]]--;
			l++;
		}
	
		resp = max(resp, r-l+1);
	}

	return resp;
} 

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	cout << solve() << endl;
}