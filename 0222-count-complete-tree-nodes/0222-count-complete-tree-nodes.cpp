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
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh=leftht(root);
        int rh=rightht(root);
        if(lh==rh) return (1<<lh)-1 ; 
        return 1+countNodes(root->left)+countNodes(root->right);
    }

    //<< means that the left-hand operand is multiplied by 2, for as many times as the number in the right-hand operand. E.g. 1 << 3 means 1*2*2*2. 
    
    int leftht(TreeNode* node){
        int cnt=0;
        while(node){
            cnt++;
            node=node->left;
        }
        return cnt;
    }
    
    int rightht(TreeNode* node){
        int cnt=0;
        while(node){
            cnt++;
            node=node->right;
        }
        return cnt;
    }
};