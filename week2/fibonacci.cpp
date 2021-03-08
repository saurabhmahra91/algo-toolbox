#include <iostream>
#define ll long long 

ll fibonacci_fast(int n) {

    ll a0 = 0;
    ll a1 = 1;
    ll temp;

    for (int i = 0; i < n; i++)
    {
        temp = a0;
        a0 = a1;
        a1 = temp + a1;
    }
    return a0;
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
