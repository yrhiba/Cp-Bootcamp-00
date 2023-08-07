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
	set<ll> st;

	string s; ll n;
	while (cin >> s >> n)
	{
		if (s == "insert")
			st.insert(n);
		else if (s == "exists")
			cout << ((st.find(n) != st.end()) ? "true" : "false") << "\n";
		else if (s == "delete")
			st.erase(n);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
