#include <bits/stdc++.h>
using namespace std;
#define ll long long

int linearSearch(int a[], int k, int l, int h)
{
    if (l==h)
    {
        if (k==a[l])
        {
            return l;
        }
        else
        {
            return -1;
        }
    }
    else if (h<l)
    {
        return -1;
    }

    if (a[l]==k)
    {
        return l;
    }
    else
    {
        return linearSearch(a, k, l+1, h);
    }
    
}


int main()
{
    int n = 2;
    int array[n] = {0,4};
    int to_find = 4;
    int low = 0;
    int high = n-1;
    cout << linearSearch(array, to_find, low, high);
    return 0;
}