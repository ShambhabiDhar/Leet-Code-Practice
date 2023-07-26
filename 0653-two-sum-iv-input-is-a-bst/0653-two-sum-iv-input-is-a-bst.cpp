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
class BSTIterator {
    std::stack<TreeNode*> st;
    bool reverse;

public:
    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        if (!reverse) {
            pushAll(node->right);
        }
        else {
            pushAll(node->left);
        }
        return node->val;
    }

private:
    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            if (reverse) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator l(root, false); // Next
        BSTIterator r(root, true);  // Before
        int i = l.next();
        int j = r.next();
        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};