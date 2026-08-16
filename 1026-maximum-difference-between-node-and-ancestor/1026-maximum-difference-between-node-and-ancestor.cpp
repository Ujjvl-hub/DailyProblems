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
private:
    int  findDiff( TreeNode* root, int mini, int maxi){
        if(root==NULL) {
            return abs(maxi-mini);
        }

        mini= min(mini, root->val);
        maxi = max(maxi,root->val);
        int left = findDiff(root->left,mini,maxi);
        int right = findDiff(root->right,mini,maxi);
        return max(left,right);
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL) return 0;
        return findDiff(root, root->val,root->val);
        
    }
};