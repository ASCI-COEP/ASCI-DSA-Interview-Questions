#User function Template for python3

class Solution:
    #Heapify function to maintain heap property.
    def heapify(self,arr, n, i):
        # code here
        
        child1 = 2*i + 1
        child2 = 2*i + 2
        
        temp=i
        
        
        if child1 < n and arr[child1] > arr[temp]:
            temp = child1
        if child2 < n and arr[child2] > arr[temp]:
            temp = child2
        if temp != i:
            arr[temp], arr[i] = arr[i], arr[temp]
            self.heapify(arr, n, temp)
    
    #Function to build a Heap from array.
    def buildHeap(self,arr,n):
        # code here

        for i in range(int(n/2)-1,-1,-1):
            #print(i)
            self.heapify(arr, n, i)
            
    
    #Function to sort an array using Heap Sort.    
    def HeapSort(self, arr, n):
        #code here
        self.buildHeap(arr, n)
        #print(arr)
        for i in range(n):
            arr[0], arr[n-i-1] = arr[n-i-1], arr[0]
            self.heapify(arr, n-i-1, 0)

#{ 
#  Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

# Contributed by : Mohit Kumara

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        Solution().HeapSort(arr,n)
        print(*arr)

# } Driver Code Ends