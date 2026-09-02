class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n= nums1.size();
        if(n==1) return true;
        bool even = false;
        bool odd = false;

        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==1) odd = true;
            else even = true;
        }

        return even || odd;
    }
};