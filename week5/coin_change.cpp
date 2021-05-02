#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dp[1001];

int mincoins(int money)
{
    if (money < 0)
    {
        return INT_MAX;
    }
    if (money == 0)
    {
        return 0;
    }

    if (dp[money]!=-1)
    {
        return dp[money];
    }

    return dp[money] = 1 + min(
            mincoins(money - 1),
            min(
                mincoins(money - 3),
                mincoins(money - 4)
                )
        );
}

int main()
{
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    cout << mincoins(n);

    return 0;
}
