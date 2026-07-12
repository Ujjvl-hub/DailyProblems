class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());

        set<int> st(temp.begin(),temp.end());
       

        // create their mapping
        map<int,int> mp;
        int r=1;
        for(int x: st){
            mp[x]= r++;
        }

        //create a resultant vector
        vector<int> ans;
        //push the ranks into it
        for(int num: arr){
            ans.push_back(mp[num]);
        }
        return ans;
    }
};