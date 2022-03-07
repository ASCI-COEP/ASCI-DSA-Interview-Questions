// Q1. Reverse an array
// https://practice.geeksforgeeks.org/problems/reverse-an-array/0

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        for (int i = N - 1; i >= 0; i--)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
