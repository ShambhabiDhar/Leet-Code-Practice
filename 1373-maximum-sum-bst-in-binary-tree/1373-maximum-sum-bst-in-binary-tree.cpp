/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class f{
  public:
    int maxi,mini,maxv,s;
    f(int maxi,int mini,int s)
    {
        this->maxi=maxi;// used for storing maximum value
        this->mini=mini;//usd for storing minimum value
       // this->maxv=maxv;
        this->s=s;// used for running valid bst sum
    }
};
int maxi=INT_MIN;// used for calculating maximum sum

class Solution {
public:
    f f1(TreeNode* root)
    {
        if(root==NULL)
            return f(INT_MIN,INT_MAX,0);// if root is null then we send sum as 0
        f l=f1(root->left);
        f r=f1(root->right);
        if(root->val>l.maxi and root->val<r.mini)// for valid bst we take maximum from left subtree and minimum fom right subtree and check if current node value lies in the range
        {
             maxi=max({maxi,l.s+r.s+root->val});//if condition is valid then 
            //only check for maximum sum which is left sum +right sum +current value of root
            return f(max(r.maxi,root->val),min(l.mini,root->val),root->val+l.s+r.s);
        }
        return f(INT_MAX,INT_MIN,0);// if not bst then we send maximum value as maximum as possible and minimum as minimum as possible so it would never be bst 
    }
    int maxSumBST(TreeNode* root) {
        maxi=INT_MIN;
        f a=f1(root);
        return (maxi<0)?0:maxi;
    }
};