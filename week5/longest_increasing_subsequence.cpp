#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<int, int> longer(pair<int, int> s1, pair<int, int> s2)
{
    int s1_l = s1.second - s1.first ;
    int s2_l = s2.second - s2.first ;
    if (s1_l >= s2_l)
    {
        return s1;
    }
    else return s2;
    
}

pair<int, int> largest_seq(int *array, int i)
{
    if (i == 0)
    {
        pair<int, int> res(0, 0);
        return res;
    }

    pair<int, int> temp;
    temp = largest_seq(array, i - 1);
    if (*(array + i) > *(array + i - 1))
    {

        temp.second += 1;
        return temp;
    }
    else
        return pair<int, int>(i, i);
}


pair<int, int> longest_subsequence(int *array, int n)
{
    pair<int, int> longest(0, 0);
    for (int i = 0; i < n; i++)
    {
        longest = longer(largest_seq(array, i), longest);
    }
    return longest;
    
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

    int dp[n];
    int max_i = 0;
    int maxx = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (array[i] > array[i - 1])
        {
            dp[i] = 1 + dp[i - 1];
        }
        if (dp[i] > maxx)
        {
            max_i = i;
            maxx = max(maxx, dp[i]);
        }
    }

    // cout << "from " << max_i - maxx + 1 << " to " << max_i << endl;

    pair<int, int> res = longest_subsequence(array, n);
    cout << res.first << ", " << res.second << endl;

    return 0;
}