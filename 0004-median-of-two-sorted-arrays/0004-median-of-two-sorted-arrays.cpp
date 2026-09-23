class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;
        while(low<=high){
            int px = low+(high-low)/2;
            int py = (m+n+1)/2 - px;

            int x1 = (px==0)?INT_MIN: nums1[px-1];
            int x2 = (px==m)?INT_MAX:nums1[px] ;

            int y1 = (py==0)?INT_MIN: nums2[py-1];
            int y2 = (py==n)?INT_MAX:nums2[py];

            if(x1<=y2 && y1<=x2){
                if((m+n)%2==1) return max(x1,y1);
                return (max(x1, y1) + min(x2, y2)) / 2.0;
            }
            
            if(x1>y2){
                high = px-1;
            }else{
                low = px+1;
            }
        }
        return 0.0;  
    }
};