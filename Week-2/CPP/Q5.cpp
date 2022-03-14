// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
   public:
   //Heapify function to maintain heap property.
   void heapify(int arr[], int n, int i)  
   {
     int pospar = i;
     int left, right;
     while (pospar<n){
         left = 2*pospar + 1;
         right = 2*pospar + 2;
         if (left<n && right<n){
             if (arr[left]<=arr[right] && arr[left]<arr[pospar])
             {
                 swap(arr[left], arr[pospar]);
                 pospar = left;
             }
             else if (arr[right]<=arr[left] && arr[right]<arr[pospar]){
                  swap(arr[right], arr[pospar]);
                  pospar = right;
             }
             else
               break;
         }
         else if (left<n){
             if (arr[left]<arr[pospar]){
                 swap(arr[left], arr[pospar]);
                 pospar = left;
             }
             else
               break;
         }
         else
           break;
     }
   }

   public:
   //Function to build a Heap from array.
   void buildHeap(int arr[], int n)  
   { 
       for (int i=n/2-1;i>=0;i--){
           heapify(arr, n, i);
       }
   }

   
   public:
   //Function to sort an array using Heap Sort.
   void heapSort(int arr[], int n)
   {
       buildHeap(arr, n);
       int arr2[n], size=0, length=n;
       for (int i=0;i<n;i++)
           arr2[i] = 0;
       arr2[size] = arr[0];
       size++;
       length--;
       if (length != 0){
           arr[0] = arr[length];
           int pospar=0;
           while (length>0){
              heapify(arr, length, pospar);
              arr2[size] = arr[0];
              size++;
              length--;
              if (length == 0)
                 continue;
              arr[0] = arr[length];
           }  
           for (int i=0;i<n;i++)
               arr[i] = arr2[i];
       }
   }
};




// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends