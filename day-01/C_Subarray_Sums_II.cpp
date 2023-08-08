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


	vector<ll> a(n+1, 0);

	map<ll, ll> mp;
	mp[0] = 1;

	ll res = 0;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];

		res += mp[a[i] - x];
		mp[a[i]]++;
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
