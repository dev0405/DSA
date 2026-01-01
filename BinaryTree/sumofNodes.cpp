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
Node* buildaTree(vector<int>& preorder){
    idx++;
    if(preorder[idx]==-1) return NULL;
    Node* root=new Node(preorder[idx]);
    root->left=buildaTree(preorder);
    root->right=buildaTree(preorder);
    return root;
}
int SumofNodes(Node* root){
    if(root==NULL) return 0;
    int leftSum=SumofNodes(root->left);
    int rightSum=SumofNodes(root->right);
    return leftSum+rightSum+root->data;
}
int main(){
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildaTree(preorder);
    cout<<root->data<<endl;
    cout<<SumofNodes(root);
}