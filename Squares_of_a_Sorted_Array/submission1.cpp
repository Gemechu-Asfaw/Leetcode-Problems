class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> ans;
        int i=0, j=0, n=nums.size();

        // Reaching to the first non-negative number
        while (i<n && nums[i]<0){
            i++;
        }

        // Placing the j at the last negative place
        j = i-1;

        // Placing the squares of elements of nums as per comparison of their absolute values
        while (i<n && j>=0){
            if (nums[i] <= abs(nums[j])){
                ans.push_back(nums[i]*nums[i]);
                i++;
            } else {
                ans.push_back(nums[j]*nums[j]);
                j--;
            }
        }

        // Placing the squares of remaining positive elements of nums
        while (i<n){
            ans.push_back(nums[i]*nums[i]);
            i++;
        }

        // Placing the squares of remaining negative elements of nums
        while (j>=0){
            ans.push_back(nums[j]*nums[j]);
            j--;
        }

        return ans;
    }
};