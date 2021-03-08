#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fiblast(ll n)
{
    ll a0 = 0;
    ll a1 = 1;
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        temp = a0;
        a0 = a1;
        a1 = (temp%10 + a1%10)%10;
    }
    return a0;
    
}

int main()
{
    ll n; cin >> n;
    cout << fiblast(n) ;
    return 0;
}