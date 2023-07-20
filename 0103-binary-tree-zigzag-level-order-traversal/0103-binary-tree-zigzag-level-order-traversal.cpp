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
#include <vector>
#include <queue>

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool lr = true; //left to right
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            
            for (int i = 0; i < size; i++) { // corrected the loop condition here
                TreeNode* node = q.front();
                q.pop();
                
                int index = (lr) ? i : (size - 1 - i);
                row[index] = node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            ans.push_back(row); // moved this line inside the while loop
            lr = !lr; // moved this line inside the while loop
        }
        
        return ans;
    }
};
