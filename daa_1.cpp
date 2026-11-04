#include <iostream>

using namespace std;

int r_fibo(int n) // TC: O(2^n) SC: O(1)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;

    return r_fibo(n - 1) + r_fibo(n - 2);
}

int r_op_fibo(int n, int n_m2, int n_m1) // TC: O(n) SC: O(1)
{
    if (n <= 0) return n_m2;
    if (n == 1) return n_m1;

    return r_op_fibo(n - 1, n_m1, n_m1 + n_m2);
}

int i_fibo(int n) // TC: O(n) SC: O(1)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int n_m2 = 0; // n minus 2
    int n_m1 = 1; // n minus 1

    for (int i = 0; i < n - 1; i++)
    {
        int curr = n_m1 + n_m2;

        n_m2 = n_m1;
        n_m1 = curr;
    }

    return n_m1;
}

int main() 
{
    int n = 0;

    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i <=n; i += 1)
        cout << i         << "\t| " 
            //  << r_op_fibo(i, 0, 1) << "\t| "
             << i_fibo(i) << "\t| "
             << r_fibo(i) << "\n";

    return 0;
}
