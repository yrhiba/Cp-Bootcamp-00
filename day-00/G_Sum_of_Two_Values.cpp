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

void solve()
{
	ll n, x; cin >> n >> x;

	vector<ll> a(n);
	map<ll, ll> mp;

	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i - 1];
		mp[a[i - 1]] = i;
	}

	for (ll i = 0; i < a.size(); i++)
	{
		ll pos = mp[x - a[i]];
		if (pos &&  ((i+1) != pos))
		{
			cout << i+1 << ' ' << pos << endl;
			return ;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
