class Solution {
public:
    int solve(vector<int> &arr, int s, int e, int target){
        if (s>e) return -1;
        int mid = s + (e-s)/2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) return solve(arr, s, mid-1, target);
        else return solve(arr, mid+1, e, target);
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums, 0, n-1, target);
    }
};