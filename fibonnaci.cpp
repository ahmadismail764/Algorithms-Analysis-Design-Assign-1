#include <bits/stdc++.h>
using namespace std;

int recursive_fib(int n) { return ((n <= 1) ? recursive_fib(n - 1) + recursive_fib(n - 2) : n); }

int main()
{
    cout << "Hello world\n";
}