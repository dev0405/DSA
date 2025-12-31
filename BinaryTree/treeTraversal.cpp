#include<iostream>
#include<vector>
#include<queue>
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
void postorderTraversal(Node* root){
    if(root==NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}
void preorderTraversal(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(Node* root){
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
void levelorderTraversal(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}
int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildtree(preOrder);
    cout<<"Tree created successfully"<<endl;
    cout<<"Post Order Traversal :"<<endl;
    postorderTraversal(root);
    cout<<endl;
    cout<<"Pre Order Traversal :"<<endl;
    preorderTraversal(root);
    cout<<endl;
    cout<<"In Order Traversal :"<<endl;
    inorderTraversal(root);
    cout<<endl;
    cout<<"Level Order Traversal :"<<endl;
    levelorderTraversal(root);
    return 0;
}