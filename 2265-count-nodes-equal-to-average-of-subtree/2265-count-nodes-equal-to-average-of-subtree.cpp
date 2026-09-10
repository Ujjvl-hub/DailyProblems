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
    int ans=0;
    pair<int,int> getAvg(TreeNode* root){
        if(root==NULL)  return{0,0};
        auto left = getAvg(root->left);
        auto right = getAvg(root->right);
        int sum = left.first+right.first+root->val;
        int count = left.second+right.second+1;
        int avg = sum/count;
        if(avg==root->val) ans++;
        return {sum,count};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        getAvg(root);
        return ans;
    }
};