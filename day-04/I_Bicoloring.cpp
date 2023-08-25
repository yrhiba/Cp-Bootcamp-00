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
# define endl "\n"
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


void solve(ll n)
{
	ll q; cin >> q;
	vector<set<ll>> grid(n+1);
	for (ll i = 0; i < q; i++)
	{
		ll a, b; cin >> a >> b;
		grid[a].insert(b);
		grid[b].insert(a);
	}

	vector<bool> color(n+1);

	queue<ll> qi;
	qi.push(1);

	color[1] = true;

	vector<bool> visited(n+1, false);
	visited[1] = true;

	while (qi.size())
	{
		ll x = qi.front();

		for (auto i = grid[x].begin(); i != grid[x].end(); i++)
		{
			if (visited[*i])
			{
				if (color[*i] == color[x])
				{
					cout << "NOT BICOLOURABLE.\n";
					return ;
				}
			}
			else
			{
				color[*i] = !color[x];
				qi.push(*i);
				visited[*i] = true;
			}
		}
		qi.pop();
	}
	cout << "BICOLOURABLE." << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	while (1)
	{
		cin >> t;
		if (!t)
			break;
		solve(t);
	}
}
