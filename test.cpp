#include <bits/stdc++.h>
using namespace std;
#define ll long long
int tenRaised(int k)
{
    int res = 1;
    while (k--)
    {
        res *= 10;
    }
    return res;
}

int kth_dig(int n, int k)
{
    if (n == n % tenRaised(k))
    {
        return n%10;
    }
    return kth_dig((n-n%10)/10, k);
}

int main()
{
    cout << kth_dig(6453, 1);
    cout << kth_dig(6453, 2);
    cout << kth_dig(6453, 3);
    cout << kth_dig(6453, 4);
    cout << kth_dig(6453, 5);
    return 0;
    
}