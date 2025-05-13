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
public:
    int solve(MountainArray &mountainArr, int target, int peak){

        int ans=-1;
        int s=0, e=peak, mid;
        
        while (s<=e){
            mid = s+(e-s)/2;
            if (mountainArr.get(mid)==target){
                ans = mid;
                e = mid-1;
            }
            else if (mountainArr.get(mid)>target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        if (ans!=-1){
            return ans;
        }

        s=peak+1;
        e=mountainArr.length()-1;

        while (s<=e){
            mid = s+(e-s)/2;
            if (mountainArr.get(mid)==target){
                ans = mid;
                s = mid+1;
            }
            else if (mountainArr.get(mid)>target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return ans;

    }

    int findPeak(MountainArray &mountainArr, int target){

        int s=0, e=mountainArr.length()-1, mid;
        while (s<e){
            mid = s+(e-s)/2;
            if (mountainArr.get(mid)>mountainArr.get(mid+1)){
                e=mid;
            }
            else{
                s=mid+1;
            }
        }

        return s;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) { 
        int peak = findPeak(mountainArr, target);
        return solve(mountainArr, target, peak);
    }
};