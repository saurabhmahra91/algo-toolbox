#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll f1(ll arr[], ll n)
{
    ll maxx = 0;
    ll second_maxx = 0;
    ll minn = 0;
    ll second_minn = 0;
    ll k;

    for (ll i = 0; i < n; i++)
    {
        k = arr[i];
        if (k > second_maxx)
        {
            second_maxx = min(maxx,k);
            maxx = max(maxx,k);
        }
        if (k < second_minn)
        {
            second_minn = max(k,minn);
            minn = min(k,minn);
        }
    }

    return max((maxx * second_maxx), (minn * second_minn));
}


int main()
{
    ll n, k;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> k;
        arr[i] = k;
    }
    cout << f1(arr, n) << endl;
    return 0;
}