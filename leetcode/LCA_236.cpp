#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    int find_num=0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(find_num==2 || root==NULL) return NULL;
        TreeNode * left=lowestCommonAncestor(root->left,p,q);
        TreeNode * right=lowestCommonAncestor(root->right,p,q);
        if(root==p || root==q){
            find_num+=1;
            return root;
        }
        if(left==NULL && right!=NULL)        return right;
        else if(left!=NULL && right==NULL)   return left;
        else if(find_num==2)   return root;
        else return NULL;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
