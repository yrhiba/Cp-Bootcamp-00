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
	ll t; cin >> t;

	stack<ll> st;
	for (ll i = 0; i < t; i++)
	{
		ll q, n;
		cin >> q;
		if (q == 1)
		{
			cin >> n;
			st.push(n);
		}
		else if (q == 2)
		{
			if (!st.empty())
				st.pop();
		}
		else if (q == 3)
		{
			if (!st.empty())
				cout << st.top() << "\n";
			else
				cout << "Empty!" << "\n";
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
