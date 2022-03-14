#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

vector<int> reverseLevelOrder(Node* root);

int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> result = reverseLevelOrder(root);
        for (int i = 0; i < result.size(); ++i)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
    return 1;
}// } Driver Code Ends


/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

vector<int> reverseLevelOrder(Node *root)
{
    stack<Node*> st;
    queue<Node*> q;
    vector<int> v;
    //Using a queue and Stack
    if(root!=NULL)
    {
        Node* current;
        q.push(root);
        while(!q.empty())
        {
            current=q.front();
            q.pop();
            if(current->right!=NULL)
                q.push(current->right);
            if(current->left!=NULL)
                q.push(current->left);
            st.push(current);
        }

        //Instead of revesing the vector we use stack for that purpose
        while(!st.empty())
        {
            Node* temp;
            temp=st.top();
            st.pop();
            v.push_back(temp->data);
        }
    }
    /*
    If we do normal level order traversal and instead of printing a node, 
    push the node to a stack and then print the contents of the deque, 
    we get “5 4 3 2 1” for the above example tree, 
    but the output should be “4 5 2 3 1”. 
    So to get the correct sequence (left to right at every level), 
    we process children of a node in reverse order, 
    we first push the right subtree to the deque, then process the left subtree.
    */
    return v;
}

