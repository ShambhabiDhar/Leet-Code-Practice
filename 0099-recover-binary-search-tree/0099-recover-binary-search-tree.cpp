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
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

private:
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        
        inorder(root->left);

        if (prev != nullptr && (root->val < prev->val)) {
            if (first == nullptr) {
                // First violation
                first = prev;
                middle = root;
            } else {
                // Second violation
                last = root;
            }
        }
        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        
        if (first && last) {
            // Two nodes are swapped, so swap their values
            std::swap(first->val, last->val);
        } else if (first && middle) {
            // Only two adjacent nodes are swapped, so swap their values
            std::swap(first->val, middle->val);
        }
        // Note: We do not need to handle the case where only 'middle' exists, as it implies
        // that only one node is misplaced, and swapping it with the 'prev' value is sufficient.
        // However, we don't need to explicitly handle that case since the code already does it correctly.
    }
};
