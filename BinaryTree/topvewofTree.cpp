#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            data=val;
            left=right=NULL;
        }
};
static int idx=-1;
Node* buildtree(vector<int>& preorder){
    idx++;
    if(preorder[idx]==-1) return NULL;
    Node* root=new Node(preorder[idx]);
    root->left=buildtree(preorder);
    root->right=buildtree(preorder);
    return root;
}

void topView(Node* root){
    queue<pair<Node*,int>> q;
    q.push({root,0});
    map<int,int> m;
    while(!q.empty()){
        Node* curr=q.front().first;
        int currHD=q.front().second;
        q.pop();
        if(m.find(currHD)==m.end()){
            m[currHD]=curr->data;
        }
        if(curr->left!=NULL){
            q.push({curr->left,currHD-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,currHD+1});
        }
    }
    for(auto it:m){
        cout<<it.second<<" ";
    }
}
int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildtree(preOrder);
    cout<<"Tree created successfully"<<endl;
    cout<<"Top View of tree :"<<endl;
    topView(root);
    return 0;
}