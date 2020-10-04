#include <bits/stdc++.h>
using namespace std;

//Author : Swoyam S Sahoo
int search(int a[100], int s, int e)
{
    if (s <= e)
    {
        int m = (s + e) / 2;
        if (a[m] > a[m - 1] && a[m] > a[m + 1])
        {
            return m;
        }
        else if (a[s] > a[m])
        {
            return search(a, s, m - 1);
        }
        else
        {
            return search(a, m + 1, e);
        }
    }
    else
    {
        return -1;
    }
}
int main()
{
    int arr[] = {11, 15, 6, 7, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 16;
    int i, j;
    i = search(arr, 0, n - 1);
    j = (i + 1) % n;
    int k = 0, ans;
    while (i != j)
    {
        ans = arr[i] + arr[j];
        if (sum < ans)
        {
            i = (i + n - 1) % n;
        }
        else if (sum > ans)
        {
            j = (j + 1) % n;
        }
        else
        {
            k = 1;
            break;
        }
    }
    if (k == 1)
    {
        cout << "Such pairs are available in the array\n";
    }
    else
    {
        cout << "No such pair is available";
    }
    return 0;
}