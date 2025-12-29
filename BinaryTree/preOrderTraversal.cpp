#include<iostream>
#include<vector>
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
void preorderTraversal(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildtree(preOrder);
    cout<<"Tree created successfully"<<endl;
    preorderTraversal(root);
    return 0;
}