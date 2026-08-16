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
    int getHeight(TreeNode* root){
        if(root==NULL) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return max(left,right)+1;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==NULL) return NULL;

        int left = getHeight(root->left);
        int right = getHeight(root->right);
        
        if(left>right){
             return subtreeWithAllDeepest(root->left);
        }
        if(right> left){
            return  subtreeWithAllDeepest(root->right);
        }
        return root;

    }
};