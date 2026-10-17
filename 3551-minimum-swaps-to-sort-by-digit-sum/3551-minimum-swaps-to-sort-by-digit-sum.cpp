class Solution {
private:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cycle = 0;
        vector<vector<int>> temp;

        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int sum =0;

            while(num>0){
                sum+=(num%10);
                num/=10;
            }
            temp.push_back({nums[i],sum,i});
        }
        sort(temp.begin(),temp.end(),cmp);
        vector<bool> visited(n,false);

        for(int i=0;i<n;i++){
            
            int curr = i;
            int count = 0;

            if(visited[curr]){
                continue;
            }else{
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = temp[curr][2];
                    count++;
                }
            }
            cycle+=(count-1);

        }

        return cycle;

    }
};