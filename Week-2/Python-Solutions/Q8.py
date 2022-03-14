#User function Template for python3

class Solution:
    
    #Function to return max value that can be put in knapsack of capacity W.
    def knapSack(self,W, wt, val, n):
        
        # code here
        mapping = {}
        
        def kns(W,wt,val,n):
            if W == 0 or n == 0:
                return 0
            if (W,n) in mapping:
                return mapping[(W,n)]
            if wt[n-1] > W:
                mapping[(W,n)] = kns(W,wt,val,n-1)
            else:
                mapping[(W,n)] = max(kns(W,wt,val,n-1),val[n-1]+kns(W-wt[n-1],wt,val,n-1))
            return mapping[(W,n)]
        return kns(W,wt,val,n)

#{ 
#  Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        W = int(input())
        val = list(map(int,input().strip().split()))
        wt = list(map(int,input().strip().split()))
        ob=Solution()
        print(ob.knapSack(W,wt,val,n))
# } Driver Code Ends