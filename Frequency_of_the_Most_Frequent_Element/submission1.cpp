class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size(), i = n-1, j = n-1, ans = 1;
        sort(nums.begin(), nums.end());

        while (i>0){
            i--;
            k = k - (nums[j]-nums[i]);
            if (k>=0){
                ans = max(ans, j-i+1);
            }
            while (k<0){
                k = k + (nums[j]-nums[j-1])*(j-i);
                j--;
            }
        }

        return ans;
    }
};