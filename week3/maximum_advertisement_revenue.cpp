#include <bits/stdc++.h>
using namespace std;
#define ll long long

void prll_vector(vector<ll> a)
{
    for (ll i = 0; i < a.size(); i++)
    {
        cout << a.at(i) << ", ";
    }
    cout << endl;
}

void inp(vector<ll> *a, ll n)
{
    ll k;
    for (ll i = 0; i < n; i++)
    {
        cin >> k;
        (*a).push_back(k);
    }
}

ll pop_max(vector<ll> *a)
{
    ll h = INT_MIN, h_i;
    for (ll i = 0; i < (*a).size(); i++)
    {
        if (h < (*a).at(i))
        {
            h = (*a).at(i);
            h_i = i;
        }
    }
    (*a).erase((*a).begin() + h_i);
    return h;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> a;
    vector<ll> b;
    inp(&a, n);
    inp(&b, n);

    ll rev = 0;
    while (n--)
    {
        rev += pop_max(&a) * pop_max(&b);
    }
    cout << rev << endl;

    return 0;
}