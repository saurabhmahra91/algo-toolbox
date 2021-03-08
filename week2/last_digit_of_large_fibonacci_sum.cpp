#include <bits/stdc++.h>
using namespace std;
#define ll long long

int fibSumLastDigit(ll n)
{
    // Reccuring period is 60 for modulo 10
    n %= 60;
    ll temp;
    ll a0 = 0;
    ll a1 = 1;
    ll s0 = a0 + a1 - 1;

    for (int i = 0; i < n; i++)
    {
        temp = a0;
        a0 = a1;
        a1 = temp + a1;
        s0 = (a0 + a1 - 1) % 10;
    }
    return s0;
}

int main()
{
    ll n;
    cin >> n;
    cout << fibSumLastDigit(n) << endl;

    return 0;
}