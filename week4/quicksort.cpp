#include <bits/stdc++.h>
using namespace std;
#define ll long long

void swap(int *a, int x1, int x2)
{
    int temp = *(a+x1);
    *(a+x1) = *(a+x2);
    *(a+x2) = temp;
    return;
}

void quicksort(int *a,int l, int h)
{
    if (h<=l)
    {
        return;
    }
    

    int pivot = *(a+l);
    int midway = l;

    for (int i = l+1; i <= h; i++)
    {
        if ( *(a+i) <= pivot )
        {
            midway++;
            swap(a, midway, i);
        }
    
    }
    swap(a, midway, l);

    quicksort(a, l, midway-1);
    quicksort(a, midway+1, h);
    
    
}

int main()
{
    int n; cin>>n;
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    quicksort(array, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << array[i] <<" ";

    }
    

    return 0;
}