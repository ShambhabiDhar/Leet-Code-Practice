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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path = "";
        backtrack(result, path, root); 
        return result;
    }

private:
    void backtrack(vector<string>& result, string path, TreeNode*& root) {
        if (!root) return;

        if (!root->left && !root->right) {
            path += to_string(root->val);
            result.emplace_back(path);
            return;
        }

        path += to_string(root->val) + "->";
        backtrack(result, path, root->left);
        backtrack(result, path, root->right);
    }
};