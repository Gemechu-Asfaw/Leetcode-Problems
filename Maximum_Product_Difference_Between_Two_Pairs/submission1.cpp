class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        
        // Sorting the vector so that the two largest numbers gets placed at the end
        // and two smallest numbers get placed at the beginning of vector
        sort(nums.begin(), nums.end());

        int N = nums.size();
        int ans = nums[N-1]*nums[N-2] - nums[1]*nums[0];
        return ans;
    }
};