class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int xo1 = 1;
        for(int i=1;i<=nums.size();i++){
            xo1^=i;
        }

        int xo2 = 1;
        for(int i=0;i<nums.size();i++){
            xo2^=nums[i];
        }
        xo1^=xo2;
        // res
        
        int RMB = xo1 & (-xo1);  // right most bit
        int a=0, b=0;

        //expected numbers
        for(int i=1;i<=nums.size();i++){
            if(i & RMB){
                a^=i;
            }else{
                b^=i;
            }
        }


        //actual numbers
        for(int i=0;i<nums.size();i++){
            if(nums[i] & RMB){
                a^=nums[i];
            }else{
                b^=nums[i];
            }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]==a){
                return {a,b};
            }
        }
         return {b,a};
        
    }
};