#User function Template for python3

class Solution:
    def findPrefixes(self, arr, N):
        lst=[]
        for i,word in enumerate(arr):
            req=False
            for j in range(len(word)):
                for k,each in enumerate(arr):
                    if i!=k and each.startswith(word[:j+1]):
                        break
                else:
                    req=word[:j+1]
                    break
            if req:
                lst.append(req)
            else:
                lst.append(word)
        return lst 

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        arr=list(map(str,input().split()))
        
        ob = Solution()
        res = ob.findPrefixes(arr,N)
        for i in res:
            print(i,end=" ")
        print()
# } Driver Code Ends