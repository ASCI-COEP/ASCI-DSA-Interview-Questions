#User function Template for python3

class Solution:
    
    #Function to return a list containing the DFS traversal of the graph.
    def dfsOfGraph(self, V, adj):
        data=[]
        visited=[-1]*V
        for q in range(V):
            if(visited[q]==-1):
                self.explore(q,adj,data,visited)
        return data
    def explore(self,v,adj,data,visited):
        visited[v]=1
        data.append(v)
        for q in adj[v]:
            if(visited[q]==-1):
                self.explore(q,adj,data,visited)


#{ 
#  Driver Code Starts
if __name__ == '__main__':
    T=int(input())
    while T>0:
        V,E=map(int,input().split())
        adj=[[] for i in range(V+1)]
        for i in range(E):
            u,v=map(int,input().split())
            adj[u].append(v)
            adj[v].append(u)
        ob=Solution()
        ans=ob.dfsOfGraph(V,adj)
        for i in range(len(ans)):
            print(ans[i],end=" ")
        print()
        T-=1
# } Driver Code Ends