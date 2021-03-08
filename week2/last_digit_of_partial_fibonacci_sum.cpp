#include <bits/stdc++.h>
using namespace std;
#define ll long long

int fibSumLastDigit(ll n)
{
    if (n<0)
    {
        return 0;
    }
    
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

int lastDigitPartialFibonacciSum(ll from, ll to)
{
    from %= 60;
    to %= 60;
    int s = (fibSumLastDigit(to) - fibSumLastDigit(from-1))%10;
    if (s<0)
    {
        s+=10;
    }
    return s;
    

}

int main()
{
    ll from, to;
    cin >> from >> to;
    cout << lastDigitPartialFibonacciSum(from, to) << endl;

    return 0;
}