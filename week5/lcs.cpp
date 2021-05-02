#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int dp2[101][101][101];

int lcsl(int *a, int *b, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (*(a + n - 1) == *(b + m - 1))
    {
        if (dp[n][m] != -1)
        {
            return dp[n][m];
        }
        return dp[n][m] = 1 + lcsl(a, b, n - 1, m - 1);
    }
    else
    {
        if (dp[n][m] != -1)
        {
            return dp[n][m];
        }

        return dp[n][m] = max(
                   lcsl(a, b, n - 1, m),
                   lcsl(a, b, n, m - 1));
    }
}

int lcsl(int *a, int *b, int *c, int n, int m, int l)
{
    if (n == 0 || m == 0 || l == 0)
    {
        return 0;
    }

    if (*(a + n - 1) == *(b + m - 1) && *(b + m - 1) == *(c + l - 1))
    {
        if (dp2[n][m][l] != -1)
        {
            return dp2[n][m][l];
        }
        return dp2[n][m][l] = 1 + lcsl(a, b, c, n - 1, m - 1, l - 1);
    }
    else
    {
        if (dp2[n][m][l] != -1)
        {
            return dp2[n][m][l];
        }

        return dp2[n][m][l] = max(
                   lcsl(a, b, c, n - 1, m, l),
                   max(
                       lcsl(a, b, c, n, m - 1, l),
                       lcsl(a, b, c, n, m, l- 1))

               );
    }
}

int main()
{
    memset(dp2, -1, sizeof dp2);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    
    int l;
    cin >> l;
    int c[l];
    for (int i = 0; i < l; i++)
    {
        cin >> c[i];
    }



    cout << lcsl(a, b, c, n, m, l);

    return 0;
}