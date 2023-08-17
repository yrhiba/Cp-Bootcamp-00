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

bool good(vector<ll> &a, ll mid, ll x)
{
	// cout << "-> " <<  mid << endl;
	ll groups = 0;
	ll sum = 0;
	for (ll i = 0; i < a.size(); i++)
	{
		if (a[i] > mid) return (false);
		if ((sum + a[i]) > mid)
		{
			groups += 1;
			sum = a[i];
			// cout << "| " << a[i];
		}
		else
		{
			sum += a[i];
			// cout << " " << a[i];
		}
	}
	if (sum)
		groups += 1;
	// cout << groups << endl;
	// cout << " -->" << groups << endl;
	return (groups <= x);
}

void solve()
{
	ll n, x; cin >> n >> x;

	vector<ll> a(n);
	ll sum = 0;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	ll mid;
	ll res=0;
	ll first = 0;
	ll last = sum;
	while (first <= last)
	{
		mid = first + ((last - first) / 2);
		// cout << mid << " ";
		if (good(a, mid, x))
		{
			last = mid - 1;
			res = mid;
		}
		else
			first = mid + 1;
		// cout << first << " " << last << endl;
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
