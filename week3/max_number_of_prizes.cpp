#include<iostream>
#include<cmath>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    ll k = floor((sqrt(8 * n + 1) - 1) / 2);
    ll extra = n - k * (k + 1) / 2;
    cout << k << endl;
    for (ll i = 1; i <= k - extra; i++)
    {
        cout << i << " ";
    }
    for (ll i = k - extra + 1; i <= k; i++)
    {
        cout << i+1 << " ";
    }

    return 0;
}