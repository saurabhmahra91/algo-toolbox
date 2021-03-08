#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(ll n)
{
    n %= 60;
    int a0 = 0;
    int a1 = 1;
    int temp;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        temp = a0;
        a0  = a1;
        a1  = (temp + a1%10 )%10;
        res += (int)pow(a0, 2)%10;
        res %= 10;
        
    }
    return res;
    

}

int main()
{
    ll n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}