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

# define mod 1000000007

using namespace std;

void print(vector<string> &a, vector< vector<ll> > &p)
{
	for (ll i = 1; i < p.size(); i++)
	{
		for (ll j = 1; j < p[i].size(); j++)
		{
			cout << p[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void solve()
{
	ll n; cin >> n;

	vector<string> a(n);
	vector< vector<ll> > p(n + 1, vector<ll>(n + 1, 0));

	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		for (ll j = 0; j < n; j++)
		{
			if (a[i][j] == '*')
				continue;

			p[i+1][j+1] = ((p[i][j+1] % mod) + (p[i+1][j] % mod)) % mod;

			if (i == 0 && j == 0)
				p[i+1][j+1] = 1;

		}
	}
	cout << p[n][n] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
