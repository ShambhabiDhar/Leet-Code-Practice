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
class Solution {
public:
    void recursion(TreeNode* root, int level, vector<int>& rsv){
        if(root==nullptr) return;
        if(rsv.size()==level) rsv.push_back(root->val);
        recursion(root->right,level+1,rsv);
        recursion(root->left,level+1,rsv);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        //reverse postorder => right left root
        vector<int> rsv;
        recursion(root,0,rsv);
        return rsv;
    }
};