class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int low = 0;
        int high= k-1;

        int sum=0;
        int count = 0;

        for(int i=low;i<k;i++){
            sum+=arr[i];
        }

        while(high<arr.size()){
            int avg = sum/k;
            if(avg>=threshold) count++;

            sum-=arr[low];
            low++;
            high++;
            if(high==arr.size()) break;
            sum+=arr[high];
        }
        return count;
    }
};