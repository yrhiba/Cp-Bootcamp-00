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

	ll r1 = 0, r2 = 0;

	bool f = true;

	vector<ll> a, b;
	ll i = n;
	while (1)
	{
		if (f)
		{
			r1 += i;
			r2 += i - 1;
			a.push_back(i);
			b.push_back(i - 1);
		}
		else
		{
			r1 += i - 1;
			r2 += i;
			a.push_back(i - 1);
			b.push_back(i);
		}
		i -= 2;
		if (i <= 1)
			break;

		f = !f;
	}
	if (i)
	{
		if (r2 < r1)
		{
			b.push_back(1);
			r2 += i;
		}
		else
		{
			a.push_back(1);
			r1 += i;
		}
	}
	if (r1 != r2)
	{
		cout << "NO" << endl;
		return ;
	}

	cout << "YES ";
	cout << a.size() << " ";
	for (ll i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << b.size() << " ";
	for (ll i = 0; i < b.size(); i++)
	{
		cout << b[i];
		if (i + 1 < b.size())
			cout << " ";
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
