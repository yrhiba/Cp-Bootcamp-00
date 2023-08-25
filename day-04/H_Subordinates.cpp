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


ll count(vector<set<ll>> &a, vector<ll> &res, ll e)
{
	res[e] = a[e].size();
	for (auto i = a[e].begin(); i != a[e].end(); i++)
		res[e] += count(a, res, *i);
	return (res[e]);
}

void solve()
{
	ll n; cin >> n;

	vector<set<ll>> a(n+1);
	vector<ll> res(n+1, -1);

	for (ll i = 2; i <= n; i++)
	{
		ll x; cin >> x;
		a[x].insert(i);
	}

	count(a, res, 1);

	for (ll i = 1; i <= n; i++)
	{
		cout << res[i];
		if (i+1 <= n)
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
