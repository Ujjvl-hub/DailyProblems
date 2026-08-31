class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int j= i+1;
        while(i<nums.size() && j<nums.size()){
            if(nums[i]==val && nums[j]!=val){
                swap(nums[i],nums[j]); 
                i++;
                j++;
            } 
            else if(nums[i]==val && nums[j]==val){
                
                while(j<nums.size() && nums[j]==val ){
                    j++;
                }
                if(j<nums.size()){
                    swap(nums[i],nums[j]);
                    i++;
                    j++;
                }
            }else{
                i++;
                j++;
            }
            
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val) count++;
        }
        return count;
    }
};