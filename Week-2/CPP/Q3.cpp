#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> vv;
        
        //issafe gives true if the queen can be placed in [row][column]
    bool issafe(vector<vector<int>> chess,int row, int column,int n)
    {
        //No Need for horizontal, lower left, lower right diagonal 
        //cuz we haven't placed anything in that yet
        for(int i=0;i<n;i++)    //Vertical
        {
            if(chess[i][column])
                return false;
        }
        
        int r=row;
        int c=column;
        while(r>0 && c>0)   //Upper Left Diagonal
        {
            if(chess[r-1][c-1])
                return false;
            r--;
            c--;
        }
    
        r=row;
        c=column;
        while(r>0 && c<n-1)     //Upper Right Diagonal
        {
            if(chess[r-1][c+1])
                return false;
            r--;
            c++;
        }
        return true;
    }    

    void solve(vector<vector<int>>&chess, int row, int column, int n, vector<int>&v)
    {
        if(row>=n)
        {
            vv.push_back(v);    //v==> Position of all Queens       vv==>Vector of All Possible position of Queens
            return ;
        }
        
        for(int i=0;i<n;i++)
        {
            if(issafe(chess,row,i,n))
            {
                 chess[row][i]=1;
                 v.push_back(i+1);    //For Returning All Possible Combination, Not needed f we have to print only 1 Solution
                                      //push_back(i+1) cuz vector is Zero Based
                 solve(chess,row+1,0,n,v);
                 
                 v.pop_back();      //Backtractking,    
                chess[row][i]=0;    //Backtractking
            }
        }
        return ;
    }

    vector<vector<int>> nQueen(int n) 
    {
        vector<vector<int>>chess(n,vector<int>(n,0));           
        vector<int> v;
        solve(chess,0,0,n,v);
        return vv;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends