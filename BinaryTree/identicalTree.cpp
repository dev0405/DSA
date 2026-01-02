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
bool isIdentical(Node* p,Node* q){
    if(p==NULL||q==NULL) return p==q;
    bool isLeftsame=isIdentical(p->left,q->left);
    bool isRightsame=isIdentical(p->right,q->right);
    return isLeftsame && isRightsame && p->data==q->data;
}
int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root1=buildtree(preOrder);
    idx=-1;
    Node* root2=buildtree(preOrder);
    bool identical=isIdentical(root1,root2);
    cout<<identical;
    return 0;
}