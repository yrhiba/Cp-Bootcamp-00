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

bool bfs(vector<vector<ll>> &g, ll x)
{
	vector<bool> visited(g.size(), false);

	queue<ll> q;

	q.push(x);

	while (q.size())
	{
		ll c = q.front();

		for (ll i = 1; i < g[c].size(); i++)
		{
			if (g[c][i] == 1 && !visited[i])
			{
				if (i == x)
					return (false);
				visited[i] = true;
				q.push(i);
			}
		}
		q.pop();
	}
	return (true);
}

void solve()
{
	ll n; cin >> n;

	vector<vector<ll>> g(n+1, vector<ll>(n+1));
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++)
			cin >> g[i][j];

	for (ll i = 1; i <= n; i++)
	{
		if (!bfs(g, i))
		{
			cout << "1" << endl;
			return ;
		}
	}
	cout << "0" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
