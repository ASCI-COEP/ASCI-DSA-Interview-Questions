// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    void filldptable(vector<long long int> &dp, int coin, int amt){
        
        for(int i=coin; i<=amt; i++){
            if(i-coin<0) continue;
            dp[i] = dp[i] + dp[i-coin];
        }
    }
  
  
    long long int count(int S[], int m, int n) {

        // code here.
        vector<long long int> dp(n+1,0);
        dp[0] = 1;
       
        
        for(int i=0; i<m; i++){
            filldptable(dp,S[i],n);
        }
        
        long long int ans=dp[n];
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends