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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        inorderTraversalHelper(root, inorder);
        return inorder;
    }
    
private:
    void inorderTraversalHelper(TreeNode* node, vector<int>& inorder) {
        if (node == nullptr) return;

        inorderTraversalHelper(node->left, inorder);
        inorder.push_back(node->val);
        inorderTraversalHelper(node->right, inorder);
    }
};
