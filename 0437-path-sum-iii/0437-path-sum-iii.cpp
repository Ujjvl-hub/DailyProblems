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
    void solve(TreeNode* root,int &targetsum,int &count,vector<int>&path){
        if(root==NULL) return ;

        path.push_back(root->val);

        solve(root->left,targetsum,count,path);
        solve(root->right,targetsum,count,path);

        long sum=0;
        for(int i=path.size()-1;i>=0;i--){
            sum=sum+path[i];
            if(sum==targetsum){
                count++;
            }
        }
        path.pop_back();
        
    } 
    int pathSum(TreeNode* root, int targetsum) {
        vector<int>path;
        int count=0;
        solve(root,targetsum,count,path);
        return count;

        
    }
};