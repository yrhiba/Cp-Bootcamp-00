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
# define ull unsigned long long
# define ll long long
ll mod = 1000000007;
using namespace std;
ll powermod(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = powermod(x, p/2) % mod;
	if (p%2)
		return ((((res * res) % mod) * (x % mod)) % mod);
	return ((res * res) % mod);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}
ll GCD(ll a, ll b)
{
	if (a < b)
		swap(a, b);
	if (b == 0)
		return (a);
	return (GCD(b, a%b));
}

void solve()
{
	ll n; cin >> n;

	vector<ll> a(n);
	vector<ll> p(n);
	vector<ll> r(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		if (!i)
			p[i] = a[i];
		else
			p[i] = GCD(a[i], p[i - 1]);
	}
	for (ll i = n-1; i >= 0; i--)
	{
		if (i == n-1)
			r[i] = a[i];
		else
			r[i] = GCD(a[i], r[i + 1]);
	}

	// return;

	ll res = 0;
	for (ll i = 0; i < n; i++)
	{
		if (i == 0)
		{
			res = r[i+1];
			// cout << r[i+1] << endl;
		}
		else if (i+1 == n)
		{
			res = max(res, p[i - 1]);
			// cout << p[i-1] << endl;
		}
		else
		{
			res = max(res, GCD(r[i+1], p[i-1]));
			// cout << GCD(r[i+1], p[i-1]) << endl;
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
