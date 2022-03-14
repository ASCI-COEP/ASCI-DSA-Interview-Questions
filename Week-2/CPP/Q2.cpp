#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
    static bool myCmp(Job a, Job b)
        return a.profit > b.profit;
    public:
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, myCmp);
        int profit = 0;
        vector<int> v(101, 0);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[arr[i].dead] == 0)
            {
                v[arr[i].dead] = arr[i].id;
                profit += arr[i].profit;
                count++;
                continue;
            }
            int j = arr[i].dead;
            while (v[j] != 0 && j > 0)
            {
                j--;
            }
            if (j != 0) //
            {
                v[j] = arr[i].id;
                profit += arr[i].profit;
                count++;
            }
        }
        return {count, profit};
    }
};
