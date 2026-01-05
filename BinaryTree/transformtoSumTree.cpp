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

void preorderTraversal(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
int sumTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftSum=sumTree(root->left);
    int rightSum=sumTree(root->right);
    root->data+=leftSum+rightSum;
    return root->data;
}

int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildtree(preOrder);
    cout<<"Tree created successfully"<<endl;
    cout<<"Pre Order Traversal :"<<endl;
    preorderTraversal(root);
    cout<<endl;
    sumTree(root);
    cout<<"Pre Order Traversal :"<<endl;
    preorderTraversal(root);
    cout<<endl;
    
    return 0;
}