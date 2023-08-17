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

void solve()
{
	ll a, b, c; cin >> a >> b >> c;

	double pres = 1e-6;

	double f = LLONG_MIN;
	double l = LLONG_MAX;
	double x = (f + l) / 2;

	double res = (a * x) + (b * sin(x)) - c;
	while (abs(res) > pres)
	{
		if (res < 0)
		{
			f = x;
			x = (f + l) / 2;
		}
		else
		{
			l = x;
			x = (f + l) / 2;
		}
		res = (a * x) + (b * sin(x)) - c;
		// cout << fixed << setprecision(6) << x << endl;
	}
	cout << fixed << setprecision(6) << x << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)
		solve();
}
