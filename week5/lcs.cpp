#include <bits/stdc++.h>
using namespace std;
#define ll long long

int lcsl(int *a, int *b, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (*(a + n - 1) == *(b + m - 1))
    {
        return 1 + lcsl(a, b, n - 1, m - 1);
    }
    else
    {
        return max(
            lcsl(a, b, n - 1, m),
            lcsl(a, b, n, m - 1));
    }
}

int main()
{
    int n, m;
    int a[n], b[m];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cout << lcsl(a, b, n, m);

    return 0;
}