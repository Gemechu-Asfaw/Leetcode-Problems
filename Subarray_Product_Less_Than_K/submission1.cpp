class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n = nums.size(), product, ans = 0;

        for (int i=0; i<n; i++){
            product = 1;
            for (int j=i; j<n; j++){
                product = product * nums[j];
                if (product < k){
                    ans++;
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};