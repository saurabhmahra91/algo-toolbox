#include <bits/stdc++.h>
using namespace std;
#define ll long long

int bin(int *a, int l, int h, int k)
{
    if (h < l)
    {
        return -1;
    }

    if (*(a + (l + h) / 2) == k)
    {
        return (l + h) / 2;
    }
    else if (*(a + (l + h) / 2) < k)
    {
        return bin(a, (l + h) / 2 + 1, h, k);
    }
    return bin(a, l, (l + h) / 2 - 1, k);
}

int main()
{
    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int nk, k;
    cin >> nk;
    for (int i = 0; i < nk; i++)
    {
        cin >> k;
        cout << bin(array, 0, n - 1, k) << " ";
    }

    return 0;
}