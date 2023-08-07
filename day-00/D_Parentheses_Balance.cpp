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
	string s; getline(cin , s);

	deque<char> dq;

	if (s.empty())
	{
		cout << "Yes" << endl;
		return ;
	}
	if (s.size() % 2)
	{
		cout << "No" << endl;
		return ;
	}

	for (ll i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[')
		{
			dq.push_back(s[i]);
		}
		else
		{
			if (s[i] == ')' && !dq.empty() && *dq.rbegin() == '(')
			{
				dq.pop_back();
				continue;
			}
			if (s[i] == ']' && !dq.empty() && *dq.rbegin() == '[')
			{
				dq.pop_back();
				continue;
			}
			cout << "No" << endl;
			return ;
		}
	}
	if (dq.empty())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s; getline(cin, s);
	ll t = stoi(s);
	while (t--)
		solve();
}
