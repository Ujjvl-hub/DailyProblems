/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int getPeak(MountainArray &mountainArr, int low, int high){
        while(low<high){
            int mid = low+(high-low)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
               low = mid+1;
            }
            else high = mid;
        }
        return low;
    }
    int getLeft(MountainArray &mountainArr, int low, int high, int target){
        while(low<=high){
            int mid = low+(high-low)/2;
            if(mountainArr.get(mid)==target) return mid;
            if(mountainArr.get(mid) > target) high = mid-1;
            else low= mid+1;
        }

        return -1;
    }

    int getRight(MountainArray &mountainArr, int low, int high, int target){
       
        
        while(low<=high && high<mountainArr.length()){
            int mid = low+(high-low)/2;
            if(mountainArr.get(mid)==target)return mid;
            if(mountainArr.get(mid) > target ) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

        int size = mountainArr.length();
        int low = 0;
        int high = size-1;

       int peak = getPeak(mountainArr,low,high);
       if(mountainArr.get(peak)== target) return peak;
       
       int left = getLeft(mountainArr,0,peak-1,target);
       if(left!=-1) return left;
       else{
            int right = getRight(mountainArr,peak+1,high,target);
            if(right!=-1) return right;
       }
       return -1;
    }
};