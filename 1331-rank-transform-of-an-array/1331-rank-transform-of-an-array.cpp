class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        //create a temp vector and copy the original one
        vector<int> temp(arr.begin(),arr.end());
        //sort it
        sort(temp.begin(),temp.end());

        // create their mapping
        map<int,int> mp;
        int r=1;
        for(int x: temp){
            if(mp.find(x)==mp.end()){
                mp[x]= r++;
            }
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