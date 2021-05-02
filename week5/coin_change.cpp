#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dp[100];

int mincoins(int *den, int nd, int money)
{
    if (money < 0)
    {
        return INT_MAX;
    }
    if (money == 0)
    {
        return 0;
    }

    int minn = INT_MAX;
    for (int i = 0; i < nd; i++)
    {
        if (money - *(den + i) >= 0)
        {
            minn = min(mincoins(den, nd, money - *(den + i)) + 1, minn);
        }
    }
    return minn;
}

int main()
{
    int money, nd;
    cin >> money >> nd;
    int array[nd];
    for (int i = 0; i < nd; i++)
    {
        cin >> array[i];
    }

    cout << mincoins(array, nd, money) << endl;

    return 0;
}