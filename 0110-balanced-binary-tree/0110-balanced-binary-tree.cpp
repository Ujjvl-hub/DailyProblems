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
int getHeight(TreeNode* root){
    if(root==NULL) return 0;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    return max(left,right)+1;
}
int solve(TreeNode* root){
    if(root==NULL) return 1;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    if(abs(left-right)>1) return -1;

    int l = solve(root->left);
    int r = solve(root->right);

    if(l==1 && r==1) return 1;
    return -1;
}
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(solve(root)==1){
            return true;
        }
        return false;
    }
};