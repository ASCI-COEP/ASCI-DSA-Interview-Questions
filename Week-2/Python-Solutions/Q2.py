#User function Template for python3

class Solution:
    
    #Function to find the maximum profit and the number of jobs done.
    def JobScheduling(self,Jobs,n):
        profit = 0
        tasks = 0
        deadlinemax = 0
        for i in range(len(Jobs)):
            deadlinemax = max(deadlinemax, Jobs[i].deadline)
        if(deadlinemax != 0):
            slots = [0]*deadlinemax
        Jobs.sort(key = lambda x: x.profit)
        Jobs.reverse()
        
        for j in range(len(Jobs)):
            k = Jobs[j].deadline - 1
            while(slots[k] != 0 and k>0):
                k -= 1
            if(slots[k] == 0):
                slots[k] = Jobs[j].profit
                
        for l in range(len(slots)):
            if(slots[l] != 0):
                profit += slots[l]
                tasks += 1
                
        return [tasks, profit]

#{ 
#  Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha
class Job:
    '''
    Job class which stores profit and deadline.
    '''
    def __init__(self,profit=0,deadline=0):
        self.profit = profit
        self.deadline = deadline
        self.id = 0

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n = int(input())
        info = list(map(int,input().strip().split()))
        Jobs = [Job() for i in range(n)]
        for i in range(n):
            Jobs[i].id = info[3*i]
            Jobs[i].deadline = info[3 * i + 1]
            Jobs[i].profit=info[3*i+2]
        ob = Solution()
        res = ob.JobScheduling(Jobs,n)
        print (res[0], end=" ")
        print (res[1])
# } Driver Code Ends