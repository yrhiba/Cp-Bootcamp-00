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
	ll n; cin >> n;
	multiset<ll> st;
	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		st.insert(t);
	}
	ll i = 0;
	for (multiset<ll>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout << *it;
		if (i+1 < n)
			cout << " ";
		i++;
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
