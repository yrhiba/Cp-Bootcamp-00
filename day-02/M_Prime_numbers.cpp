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
	ll m, n; cin >> m >> n;

	vector<bool> isprime(n+1, true);
	isprime[0] = isprime[1] = false;

	for (ll i = 2; i <= n; i++)
	{
		if (!isprime[i]) continue;
		for (ll j = i*i; j <= n; j+=i)
			isprime[j] = false;
	}
	bool f = false;
	for (ll i = m; i <= n; i++)
	{
		if (isprime[i])
		{
			cout << i << "\n";
			f = true;
		}
	}
	if (!f)
		cout << "Absent\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();

}
