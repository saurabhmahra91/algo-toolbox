#include <bits/stdc++.h>
using namespace std;
#define ll long long

void merge(int *a, int l, int h)
{
    int mid = (l + h) / 2;
    int sorted[h - l + 1];
    int sorted_length = 0;
    int i = l, j = mid+1;

    while ((i <= mid && j <= h))
    {
        if (*(a + i) < *(a + j))
        {
            sorted[sorted_length] = *(a + i);
            i++;
        }
        else
        {
            sorted[sorted_length] = *(a + j);
            j++;
        }
        sorted_length++;
    }
    while (i <= mid)
    {
        sorted[sorted_length] = *(a + i);
        sorted_length++;
        i++;
    }
    while (j <= h)
    {
        sorted[sorted_length] = *(a + j);
        sorted_length++;
        j++;
    }

    for (int x = 0; x <= h-l; x++)
    {
        *(a + l + x ) = sorted[x];
    }

    return;
}

void mergeSort(int *a, int l, int h)
{
    if (l >= h)
    {
        return;
    }

    mergeSort(a, l, (l + h) / 2);
    mergeSort(a, (l + h) / 2 + 1, h);
    merge(a, l, h);
    return;
}

bool majority(int *a, int n)
{
    mergeSort(a, 0, n-1);
    int majority_element = *(a+(n-1)/2);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(a+i)==majority_element)
        {
            count ++;
        }
        
    }
    return ( count > n/2 );
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
    cout << majority(array, n) << endl;;

    return 0;
}