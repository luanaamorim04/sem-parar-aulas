#include <iostream>
#define esq(x) (2*x)
#define dir(x) ((2*x) + 1)
#define MAXN (int) (2e5 + 5)
#define INF (1e9)
#define int long long

using namespace std;

int n, q, a, b, arr[MAXN], st[MAXN*4], op;

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = arr[i];
		return;
	}

	int mid = (i+j)/2;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = st[esq(idx)]+st[dir(idx)];
}

int query(int idx, int i, int j, int l, int r)
{
	if (i >= l && j <= r) return st[idx];
	if (i > r || j < l) return 0;

	int mid = (i+j)/2;
	int x = query(esq(idx), i, mid, l, r);
	int y = query(dir(idx), mid+1, j, l, r);
	return x+y;
}

void update(int idx, int i, int j, int pos, int val)
{
	if (i == j) 
	{
		st[idx] = val;
		return;
	}

	int mid = (i+j)/2;
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);

	st[idx] = st[esq(idx)]+st[dir(idx)];
}

int32_t main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	build(1, 1, n);
	while (q--)
	{
		cin >> op >> a >> b;
		if (op == 1) 
		{
			update(1, 1, n, a, b);
		}
		else
		{
			cout << query(1, 1, n, a, b) << endl;
		}
	}

	return 0;
}