#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <numeric>
# define ull unsigned long long
# define ll long long
const ll mod = 1e9 + 7;
using namespace std;
ll powermod(ll x, ll p, ll m)
{
	if (p == 0) return (1);
	ll res = powermod(x, p/2, m) % m;
	if (p%2)
		return ((((res * res) % m) * (x % m)) % m);
	return ((res * res) % m);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}
ll gcd(ll a, ll b)
{
	if (b == 0) return (a);
	return (gcd(b, a%b));
}
ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a,b));
}
ll inverse(ll x, ll m)
{
	return (powermod(x, m-2, m));
}

ll bfs(vector<set<ll>> &f, vector<ll> &v, ll x)
{
	vector<bool> vis(f.size(), false);
	vis[x] = true;

	v[x] = x;

	queue<ll> q;

	q.push(x);

	ll res = 0;

	while (q.size())
	{
		ll o = q.front();
		v[o] = x;
		res += 1;

		for (auto i = f[o].begin(); i != f[o].end(); i++)
		{
			if (!vis[*i])
			{
				q.push(*i);
				vis[*i] = true;
			}
		}
		q.pop();
	}
	return (res);
}

void solve()
{
	ll n, m; cin >> n >> m;

	vector<set<ll>> firends(n+1);

	for (ll i = 0; i < m; i++)
	{
		ll k, t; cin >> k;
		vector<ll> a(k);
		for (ll j = 0; j < k; j++)
		{
			cin >> a[j];
			if (j)
			{
				firends[a[j-1]].insert(a[j]);
				firends[a[j]].insert(a[j-1]);
			}
		}
	}


	// cout << "Friends:\n";
	// for (ll i = 1; i <= n; i++)
	// {
	// 	cout << i << ": ";
	// 	for (auto x = firends[i].begin(); x != firends[i].end(); x++)
	// 	{
	// 		cout << *x << " ";
	// 	}
	// 	cout << endl;
	// }

	vector<ll> res(n+1);
	vector<ll> vis(n+1);
	for (ll i = 1; i <= n; i++)
	{
		if (!vis[i])
			res[i] = bfs(firends, vis, i);
		else
			res[i] = res[vis[i]];

		cout << res[vis[i]];

		if (i+1<=n)
			cout << " ";
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
