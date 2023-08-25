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
int dr[] = {+1, -1, 0, 0};
int dc[] = {0, 0, +1, -1};
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

void bfs(vector<string> &grid, ll i, ll j)
{
	grid[i][j] = '#';

	queue<ll> qr;
	queue<ll> qc;

	qr.push(i);
	qc.push(j);

	while (qr.size())
	{
		ll ii = qr.front();
		ll jj = qc.front();

		for (ll x = 0; x < 4; x++)
		{
			ll ni = ii + dr[x];
			ll nj = jj + dc[x];

			if (grid[ni][nj] == '.')
			{
				grid[ni][nj] = '#';

				qr.push(ni);
				qc.push(nj);
			}
		}
		qr.pop();
		qc.pop();
	}
}

void solve()
{
	ll n, m; cin >> n >> m;

	vector<string> grid(n+2, string(m+2, '#'));

	for (ll i = 1; i <= n; i++)
	{
		cin >> grid[i];
		grid[i] = '#' + grid[i] + '#';
	}

	ll res = 0;
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= m; j++)
		{
			if (grid[i][j] == '.')
			{
				res += 1;
				bfs(grid, i, j);
			}
		}
	}
	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
