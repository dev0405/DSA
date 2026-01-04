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
Node* LCA(Node* root,Node* p,Node* q){
    if(root==NULL){
        return NULL;
    }
    if(root->data==p->data ||root->data==q->data){
        return root;
    }
    Node* leftLCA=LCA(root->left,p,q);
    Node* rightLCA=LCA(root->right,p,q);
    if(leftLCA && rightLCA){
        return root;
    }else if(leftLCA!=NULL){
        return leftLCA;
    }else{
        return rightLCA;
    }
}
int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildtree(preOrder);
    cout<<"Tree created successfully"<<endl;
    Node* p=new Node(2);
    Node* q=new Node(3);
    Node* ans=LCA(root,p,q);
    cout<<ans->data;
}