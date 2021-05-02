#include <bits/stdc++.h>
using namespace std;
#define ll long long

void a(int b[])
{
    b[0] = 99;
    b[1] = 100;
    return;

}

int main()
{
    int b[2] = {0, 1};
    a(b);
    cout<< b[0] << endl;
    cout<< b[1] << endl;
    return 0;
}