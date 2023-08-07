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

	vector< priority_queue<ll> > a(n);

	ll qtype, t, x;
	for (ll i = 0; i < q; i++)
	{
		cin >> qtype;
		if (qtype == 0)
		{
			cin >> t >> x;
			a[t].push(x);
		}
		else if (qtype == 1)
		{
			cin >> t;
			if (a[t].empty())
				continue;
			cout << a[t].top() << "\n";
		}
		else if (qtype == 2)
		{
			cin >> t;
			if (a[t].empty())
				continue;
			a[t].pop();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
