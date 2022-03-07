#User function Template for python3

class Solution:
    def count(self, S, m, n): 
        # code here 
        T = [0] * (n + 1)
        T[0] = 1
     
        for i in range(len(S)):
            j = S[i]
            while j <= n:
                T[j] += T[j - S[i]]
                j = j + 1
     
        return T[n]


#{ 
#  Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        n,m = list(map(int, input().strip().split()))
        S = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.count(S,m,n))
# } Driver Code Ends