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

	vector<ll> fib(n, 1);
	if (n == 0 || n == 1)
	{
		cout << 1 << endl;
		return ;
	}
	for (ll i = 2; i <= n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	cout << fib[n] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
