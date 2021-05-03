#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool partition_possible(int *a, int n, int v1, int v2, int v3)
{
    if (n==0)
    {
        if (v1 == v2 && v2 == v3)
        {
            return true;
        }
        else return false;
        
    }
    return partition_possible(a, n-1, v1-a[n-1], v2, v3) || partition_possible(a, n-1, v1, v2-a[n-1], v3) || partition_possible(a, n-1, v1, v2, v3-a[n-1]) ;
    
}

int main()
{
    int n; cin>>n;
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int v1 = 0, v2 = 0, v3 = 0;
    cout << partition_possible(array, n, v1, v2, v3);

    return 0;
}