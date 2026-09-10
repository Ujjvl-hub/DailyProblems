class Solution {
public:
    void combination(int ind, vector<vector<int>>&ans,vector<int>&ds,vector<int>&candidates,int target){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(target<candidates[i] ) break;

            ds.push_back(candidates[i]);
            combination(i+1,ans,ds,candidates,target-candidates[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        combination(0,ans,ds,candidates,target);
        return ans;

    }

};