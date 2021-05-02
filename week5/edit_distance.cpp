#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dp[101][101];

int edit_distance(string a, string b, int n, int m)
{
    // cout << n << ", "<<  m << endl;
    if (m == 0 || n == 0)
    {
        if (m == 0)
        {
            return dp[n][0] = n;
        }
        else
        {
            return dp[0][m] = m;
        }
    }

    if (a[n - 1] == b[m - 1])
    {
        if (dp[n - 1][m - 1] != -1)
        {
            return dp[n - 1][m - 1];
        }
        return dp[n - 1][m - 1] = edit_distance(a, b, n - 1, m - 1);
    }
    else
    {

        if (dp[n][m] != -1)
        {
            return dp[n][m];
        }
        else
        {
            return dp[n][m] = 1 + min(
                edit_distance(a, b, n - 1, m - 1),
                min(
                    edit_distance(a, b, n - 1, m),
                    edit_distance(a, b, n, m - 1)
                )

            );
        }
    }
}
int main()
{
    memset(dp, -1, sizeof(dp));
    string a, b;
    cin >> a >> b;
    cout << edit_distance(a, b, a.size(), b.size());
    return 0;
}