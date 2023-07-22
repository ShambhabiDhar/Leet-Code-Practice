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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) return nullptr;
        map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }
        return buildTreePostIn(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
    }

    TreeNode* buildTreePostIn(vector<int>& postorder, int ps, int pe, vector<int>& inorder, int is, int ie, map<int, int>& inmap) {
        if (ps > pe || is > ie) return nullptr;
        TreeNode* root = new TreeNode(postorder[pe]);
        int ri = inmap[postorder[pe]];
        int numLeft = ri - is;
        root->left = buildTreePostIn(postorder, ps, ps + numLeft - 1, inorder, is, ri - 1, inmap);
        root->right = buildTreePostIn(postorder, ps + numLeft, pe - 1, inorder, ri + 1, ie, inmap);
        return root;
    }
};






