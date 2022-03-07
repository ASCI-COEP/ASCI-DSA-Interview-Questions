#User function Template for python3
class Solution:
    def isPalindrome(self, S):
        # code here
        L=list(S)
        reverse_L=L[::-1]
        reverse_S="".join(reverse_L)
        if(reverse_S==S):
            return 1
        else:
            return 0

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        S = input()
        ob = Solution()
        answer = ob.isPalindrome(S)
        print(answer)

# } Driver Code Ends