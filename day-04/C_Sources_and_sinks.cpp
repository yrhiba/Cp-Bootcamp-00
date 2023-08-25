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


void solve()
{
	ll n, o; cin >> n;

	vector<ll> x(n, 0), y(n, 0);
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			cin >> o;
			if (o == 1)
			{
				x[j] = 1;
				y[i] = 1;
			}
		}
	}

	ll r, l; r = l = 0;
	for (ll i = 0; i < n; i++)
	{
		if (x[i] == 0) r++;
		if (y[i] == 0) l++;
	}
	cout << r;
	for (ll i = 0; i < n; i++)
	{
		if (x[i] == 0)
			cout << " " << i+1;
	}
	cout << "\n";
	cout << l;
	for (ll i = 0; i < n; i++)
	{
		if (y[i] == 0)
			cout << " " << i+1;
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
