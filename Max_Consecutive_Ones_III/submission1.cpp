class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size(), i = 0, j = 0, zeros = 0, ans = 0;

        while (j<n){
            
            while (j<n && (nums[j]==1 || zeros<k)){
                cout << i << " " << j << endl;
                ans = max(ans, j-i+1);
                if (nums[j] == 0) zeros++;
                j++;
            }

            while (zeros>=k && i<=j){
                if (nums[i] == 0) zeros = max(zeros-1, 0);
                i++;
            }

            if (i>j) j++;
        }

        return ans;
    }
};