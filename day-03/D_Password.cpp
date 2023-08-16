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
    ll n; cin >> n;

    map<ll, ll> a;
    ll x;
    for (ll i = 0; i < n; i++)
    {
        cin >> x;
        a[x] = 1;
    }

    set<ll> r;
    for (ll i = 0; i <= 9; i++)
    {
        if (a.find(i) == a.end())
            r.insert(i);
    }

    cout << r.size() * (r.size() - 1) * 3 << endl;
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
