#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, res=0;
    cin >> n;
    res += n/10;
    n %= 10;
    res += n/5;
    n %= 5;
    res += n;
    cout << res << endl;


    return 0;
}