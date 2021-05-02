#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 1 - 2 basecase version, there is also a better implementation below
int binarySearch(int a[], int k, int l, int h)
{
    if (l == h)
    {
        if (a[l] == k)
        {
            return l;
        }
        else
        {
            return l;
        }
    }
    int mid = (l + h) / 2;
    if (a[mid] < k)
    {
        return binarySearch(a, k, mid + 1, h);
    }
    else
    {
        return binarySearch(a, k, l, mid);
    }
}




// 0 - 1 basecase version
int binaryIndex(int a[], int k, int l, int h)
{
    if (l==h+1)
    {
        return l;
    }
    int mid = (l+h)/2;
    if (a[mid] > k)
    {
        return binaryIndex(a, k, l, mid-1);
    }
    else if (a[mid]==k)
    {
        return mid;
    }
    else
    {
        return binaryIndex(a, k, mid+1, h);
    }
    
    
}




int main()
{
    int a[5] = {0, 1, 3, 4, 5};
    cout << endl;
    cout << binaryIndex(a, 2, 0, 4) << endl;
    return 0;
}