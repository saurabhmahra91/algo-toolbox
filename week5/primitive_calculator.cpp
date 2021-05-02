#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <int> dp[1000001];
int min(int a, int b, int c)
{
    return min(a, min(b, c));
}
void print(vector<int> a)
{
    for (int i = a.size()-1; i>=0; i--)
    {
        cout << a.at(i) << " ";
    }
    cout << endl;
}

vector<int> smallest(vector<int> a, vector<int> b, vector<int> c)
{
    int l1 = a.size();
    int l2 = b.size();
    int l3 = c.size();
    if (l1 == min(l1, min(l2, l3)))
    {
        return a;
    }
    else if (l2 == min(l1, min(l2, l3)))
    {
        return b;
    }
    else
    {
        return c;
    }
}
vector<int> smallest(vector<int> a, vector<int> b)
{
    int l1 = a.size();
    int l2 = b.size();
    if (l1 == min(l1, l2))
    {
        return a;
    }
    else
    {
        return b;
    }
}

vector<int> optimal_sequence(int n, vector<int> seq)
{
    // cout << n << ": ";
    print(seq);
    if (n == 1)
    {
        return seq;
    }
    if (dp[n].at(0) != -1)
    {
        return dp[n];
    }
    
    if (n % 6 == 0)
    {
        vector<int> res1 = seq;
        vector<int> res2 = seq;
        vector<int> res3 = seq;
        res1.push_back(n / 3);
        res2.push_back(n / 2);
        res3.push_back(n - 1);
        return dp[n] = smallest(
            optimal_sequence(n/3, res1),
            optimal_sequence(n/2, res2),
            optimal_sequence(n-1, res3)

        );
    }
    else if (n % 2 == 0 && n % 3 != 0)
    {
        vector<int> res1 = seq;
        vector<int> res2 = seq;
        res1.push_back(n / 2);
        res2.push_back(n - 1);
        return dp[n] = smallest(
            optimal_sequence(n / 2, res1),
            optimal_sequence(n - 1, res2)

        );
    }

    else if (n % 3 == 0 && n % 2 != 0)
    {
        vector<int> res1 = seq;
        vector<int> res2 = seq;
        res1.push_back(n / 3);
        res2.push_back(n - 1);
        return dp[n] = smallest(
            optimal_sequence(n / 3, res1),
            optimal_sequence(n - 1, res2)

        );
    }
    else
    {
        vector<int> res1 = seq;
        res1.push_back(n - 1);
        return dp[n] = optimal_sequence(n - 1, res1);
    }
}

int main()
{
    vector<int> empty;
    empty.push_back(-1);
    for (int i = 0; i < 1000001; i++)
    {
        dp[i] = empty;
    }
    int n;
    cin >> n;
    vector<int> seq;
    seq.push_back(n);
    print(optimal_sequence(n, seq));
    return 0;
}