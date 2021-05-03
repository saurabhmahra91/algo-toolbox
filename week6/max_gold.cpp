#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dp[10001][301];

int max_weight( int *array, int n, int w)
{

    if (n==0 || w==0)
    {
        return 0;
    }
    if (dp[w][n]!=-1)
    {
        return dp[w][n];
    }
    
    if (*(array+n-1) <= w)
    {
        
        return dp[w][n]= max(max_weight(array, n-1, w-*(array+n-1)) + *(array+n-1), max_weight(array, n-1, w));
    }
    else return dp[w][n] = max_weight(array, n-1, w);
    
    
}

int main()
{
    memset(dp, -1, sizeof dp);
    int n, W; cin>>W>>n;
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << max_weight(array, n, W);
    

    return 0;
}