#include <bits/stdc++.h>
using namespace std;
#define ll long long

//! array pointer, not array

void merge(int a[], int l, int m, int h)
{

    int b[h - l + 1];
    int i = l, j = m + 1, count = 0;
    while (i <= m && j <= h)
    {

        if (a[i] <= a[j])
        {
            b[count] = a[i];
            i++;
        }
        else
        {
            b[count] = a[j];
            j++;
        }
        count++;
    }

    while (i <= m)
    {
        b[count] = a[i];
        i++;
        count++;
    }

    while (j <= h)
    {
        b[count] = a[j];
        j++;
        count++;
    }

    for (int i = h; i >= l; i--)
    {
        a[i] = b[count-1];
        count --;
    }
    

    return;
}

void mergeSort(int a[], int l, int h)
{
    if (l == h)
    {
        return;
    }

    mergeSort(a, l, (l + h) / 2);
    mergeSort(a, (l + h) / 2 + 1, h);
    merge(a, l, (l + h) / 2, h);
    return;
}

int main()
{

    int n;
    int a[2] = {4, 2};
    mergeSort(a, 0, 1);
    return 0;
}