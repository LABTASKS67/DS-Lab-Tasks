#include <iostream>
using namespace std;

int maxi(int a[], int n, int i, int m)
{
    if (i == n)
    {
        return m;
    }

    if (a[i] > m)
    {
        m = a[i];
    }

    return maxi(a, n, i + 1, m);
}

bool sum(int a[], int n, int i, int t, bool take)
{
    if (t == 0 && take)
    {
        return true;
    }

    if (i == n || t < 0)
    {
        return false;
    }

    return sum(a, n, i + 1, t - a[i], true) ||
        sum(a, n, i + 1, t, take);
}

int mag(int a[], int n)
{
    if (n == 0)
    {
        return -1;
    }

    int m = maxi(a, n, 0, a[0]);

    int b[100];

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != m)
        {
            b[k] = a[i];
            k++;
        }
    }

    if (sum(b, k, 0, m, false))
    {
        return m;
    }

    return mag(b, k);
}

void display(int a[], int n, int i)
{
    if (i == n)
    {
        return;
    }

    cout << a[i] << " ";

    display(a, n, i + 1);
}

int main()
{
    int a[] = { 2, 3, 5, 8, 13 };
    int n = 5;
    cout << "array: ";
    display(a, n, 0);
    int x = mag(a, n);
    cout << "\nmagic number: " << x;
    return 0;
}