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
// int getHeight(TreeNode* root){
//     if(root==NULL) return 0;
//     int left = getHeight(root->left);
//     int right = getHeight(root->right);
//     return max(left,right)+1;
// }
// int solve(TreeNode* root){
//     if(root==NULL) return 1;
//     int left = getHeight(root->left);
//     int right = getHeight(root->right);
//     if(abs(left-right)>1) return -1;

//     int l = solve(root->left);
//     int r = solve(root->right);

//     if(l==1 && r==1) return 1;
//     return -1;
// }
    pair<bool,int> solve(TreeNode* root){
        if(root==NULL) return {true,0};
        pair<bool,int> left = solve(root->left);
        pair<bool,int> right = solve(root->right); 
        int height = max(left.second,right.second)+1;

        pair<bool,int> res;
        if(left.first && right.first && abs(left.second-right.second)<=1){
            res.first= true;
        }else{
            res.first = false;
        }
        res.second = height;
        return res;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        return solve(root).first;
    }
};