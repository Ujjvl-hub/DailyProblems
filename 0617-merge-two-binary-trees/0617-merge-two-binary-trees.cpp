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
    TreeNode* solve(TreeNode* root1,TreeNode* root2, TreeNode* res){
        if(root1==NULL && root2==NULL) return NULL;
        if(root1==NULL && root2!=NULL) return root2;
        if(root1!=NULL && root2==NULL) return root1;

        int val = root1->val+ root2->val;
        res = new TreeNode(val);
        res->left = solve(root1->left, root2->left,res);
        res->right = solve(root1->right,root2->right,res);
        return res;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* res = NULL;
        res = solve(root1,root2,res);
        return res;
    }
};