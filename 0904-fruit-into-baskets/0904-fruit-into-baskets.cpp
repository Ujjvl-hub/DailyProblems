class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;

        int ans = 0;

        int low =0;
        for(int high = 0;high < fruits.size() ; high++){
            mp[fruits[high]]++;

            if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[low]]--;
                    if(mp[fruits[low]] == 0){
                        mp.erase(fruits[low]);
                    }
                    low++;
                }
            }

            int len = high-low +1;
            ans = max(ans,len);

        }
        return ans;
    }
};