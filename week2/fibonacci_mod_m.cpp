#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll modFib(ll n, ll m)
{
    ll a0 = 0;
    ll a1 = 1;
    ll temp, period;
    ll PERIOD_UPPER_LIM= 10000;
    for (ll i = 0; i < PERIOD_UPPER_LIM; i++)
    {
        temp = a0;
        a0 = a1;
        a1 = (temp % m + a1 % m) % m;
        if (a0 == 0 && a1 == 1)
        {
            period = i+1;
            break;
        }
    }

    n = n % period;
    a0 = 0;
    a1 = 1;

    for (ll i = 0; i < n; i++)
    {
        temp = a0;
        a0 = a1;
        a1 = (temp % m + a1 % m) % m;
    }

    return a0;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    cout << modFib(n, m) << " ";

    return 0;
}