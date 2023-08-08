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
	ll n, d; cin >> n >> d;

	string s; cin >> s;

	ll f = 0;
	ll i = 0;
	while ( i < n )
	{
		if ((s[i] - '0') >= d)
			cout << s[i];
		else
		{
			f = 1;
			cout << (char)(d + '0');
			break;
		}
		i++;
	}
	while (i < n)
		cout << s[i++];
	if (f == 0)
		cout << (char)(d + '0');
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)
		solve();
}
