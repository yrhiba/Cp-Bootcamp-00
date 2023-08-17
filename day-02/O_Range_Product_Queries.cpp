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
	ll n, q; cin >> n >> q;

	vector<ll> a(n+1, 1);
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] = ((a[i - 1] % mod) * (a[i] % mod)) % mod;
	}

	for (ll i = 0; i < q; i++)
	{
		ll l, r; cin >> l >> r;
		// a[r] / a[l - 1]; 
		cout << ((a[r]%mod) * powermod(a[l - 1], mod - 2)) % mod  << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
