#include <iostream>
#include <numeric>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MAXN (int)(1e5 + 10)

using namespace std;

struct tree
{
	int val, freq;
};

tree st[MAXN<<2], vazio;
int n, m, arr[MAXN], l, r;

tree join(tree esq, tree dir)
{
	if (esq.val == -1) return dir;
	if (dir.val == -1) return esq;
	tree r;
	if (esq.val == dir.val) r.val = esq.val, r.freq = esq.freq + dir.freq;
	else if (esq.val % dir.val == 0) r = dir;
	else if (dir.val % esq.val == 0) r = esq;
	else r = {gcd(esq.val, dir.val), 0};
	return r;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx].val = arr[i];
		st[idx].freq = 1;
		return;
	}
	int mid = (i+j)>>1;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

tree query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return vazio;
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	tree x = query(esq(idx), i, mid, l, r);
	tree y = query(dir(idx), mid+1, j, l, r);
	tree R = join(x, y);
	return join(x, y);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	vazio = {-1, -1};
	build(1, 1, n);
	cin >> m;
	while (m--)
	{
		cin >> l >> r;
		cout << (r-l+1) - query(1, 1, n, l, r).freq << endl;
	}
}
