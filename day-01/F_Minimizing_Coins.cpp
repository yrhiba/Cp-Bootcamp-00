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

# define ll long long

using namespace std;


ll calc(vector<ll> &a, ll x, ll pos, ll coins)
{
	if (pos >= a.size() && x == 0)
		return (coins);
	if (pos >= a.size())
		return (-1);

	ll can_take = x / a[pos];

	ll res = calc(a, x, pos + 1, coins);

	for (ll i = 1; i <= can_take; i++)
	{
		ll t = calc(a, x - (i * a[pos]), pos + 1, coins + i);

		if (t != -1)
		{
			if (res != -1)
				res = min(res, t);
			else
				res = t;
		}
	}
	return (res);
}

void solve()
{
	ll n, x; cin >> n >> x;

	vector<ll> a(n);

	for (ll i = 0; i < n; i++)
		cin >> a[i];

	vector<ll> b(x+1, -1);
	b[0] = 0;

	for (ll i = 1; i <= x; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			if (i - a[j] >= 0)
			{
				ll t = (b[i - a[j]] != -1) ? 1 + b[i - a[j]] : -1;
				if (t != -1)
				{
					if (b[i] == -1)
						b[i] = t;
					b[i] = min(t, b[i]);
				}
			}
		}
	}
	cout << b[x] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
