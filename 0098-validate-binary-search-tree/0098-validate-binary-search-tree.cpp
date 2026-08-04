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
   bool check(TreeNode* root, TreeNode* mini, TreeNode* maxi){
        if(root==NULL) return true;
        if(mini!=NULL && root->val<= mini->val) return false;
        if(maxi !=NULL && root->val >= maxi->val) return false;

        bool left = check(root->left,mini,root);
        bool right = check(root->right, root,maxi);
        return left && right;

   }
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        return check(root,NULL,NULL);

    }
};