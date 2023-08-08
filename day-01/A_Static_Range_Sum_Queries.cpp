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
	ll n, q; cin >> n >> q;

	vector<ll> a(n + 1, 0);
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (ll i = 0; i < q; i++)
	{
		ll l, r; cin >> l >> r;
		cout << a[r] - a[l - 1] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
