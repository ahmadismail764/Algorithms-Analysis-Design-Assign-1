#include <bits/stdc++.h>
using namespace std;

int recursive_fib(int n) { return ((n <= 1) ? recursive_fib(n - 1) + recursive_fib(n - 2) : n); }

void matrix_multiplier(int F[2][2], int M[2][2])
{
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
void matrix_power(int F[2][2], int n)
{
    if (n == 0 || n == 1)
        return;
    int M[2][2] = {{1, 1}, {1, 0}};
    matrix_power(F, n / 2);
    matrix_multiplier(F, F);
    if (n % 2)
        matrix_multiplier(F, M); // Multiply by base matrix if n is odd
}
int divandconq_fib(int n)
{
    if (n == 0)
        return n;
    int F[2][2] = {{1, 1}, {1, 0}};
    matrix_power(F, n - 1);
    return F[0][0];
}

int dynamic_fib(int n)
{
    static int dp_fib[1000] = {-1};
    if (n <= 1)
        return n;
    if (dp_fib[n])
        return dp_fib[n];
    dp_fib[n] = dynamic_fib(n - 1) + dynamic_fib(n - 2);
    return dp_fib[n];
}
int main()
{
    cout << recursive_fib(5) << '\n';
    cout << divandconq_fib(10) << '\n';
    cout << dynamic_fib(20) << '\n';
}