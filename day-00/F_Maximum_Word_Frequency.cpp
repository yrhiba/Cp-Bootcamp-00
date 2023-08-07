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

	string mf;
	map<string, ll> mp;
	for (ll i = 0; i < n; i++)
	{
		string s; cin >> s;
		mp[s] += 1;

		if (i == 0)
			mf = s;
		else
		{
			if (mp[mf] == mp[s])
				mf = max(mf, s);
			else if (mp[mf] < mp[s])
				mf = s;
		}
	}
	cout << mf << " " << mp[mf] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
