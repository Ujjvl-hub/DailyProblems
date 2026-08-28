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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;

        queue<TreeNode*> q;
        q.push(root);

        bool LtR = true;

        while(!q.empty()){
            int n = q.size();
            vector<int> temp(n);

            for(int i=0;i<n;i++){
                auto p = q.front();
                q.pop();

                int idx = LtR? i : n-i-1;
                temp[idx] = p->val;
                
                if(p->left){
                    q.push(p->left);
                }

                if(p->right){
                    q.push(p->right);
                }
            }
            LtR = !LtR;
            res.push_back(temp);
        }
        return res;
    }
};