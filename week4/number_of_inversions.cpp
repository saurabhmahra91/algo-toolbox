#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n; cin>>n;
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (array[j] < array[i])
            {
                count ++;
            }
            
        }
        
    }
    cout << count << endl;
    
    return 0;
}