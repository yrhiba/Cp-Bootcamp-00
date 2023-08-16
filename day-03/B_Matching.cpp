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
#include <numeric>
# define ull unsigned long long
# define ll long long
const ll mod = 1000000007;
using namespace std;
ll powermod(ll x, ll p, ll m)
{
    if (p == 0) return (1);
    ll res = powermod(x, p/2, m) % m;
    if (p%2)
        return ((((res * res) % m) * (x % m)) % m);
    return ((res * res) % m);
}
ll power(ll x, ll p)
{
    if (p == 0) return (1);
    ll res = power(x, p/2);
    if (p%2)
        return ((res * res) * x);
    return (res * res);
}
ll gcd(ll a, ll b)
{
    if (b == 0) return (a);
    return (b, a%b);
}
ll lcm(ll a, ll b)
{
    return ((a*b)/gcd(a,b));
}


void solve()
{
    string s; cin >> s;

    ll res = 1;
    for (ll i = 0; i < s.size(); i++)
    {
        if (i==0 && s[i] == '?')
            res *= 9;
        else if (s[i] == '?')
            res *= 10;
    }
    if (s[0] == '0')
    {
        cout << 0 << "\n";
        return ;
    }
    cout << res << "\n";
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
