class Solution {
public:
    int getGPD(int n){
        int i = 2;
        while (i*i <= n){
            if (n % i == 0) return n/i;
            else i++;
        }
        return 1;
    }

    int minOperations(vector<int>& nums) {
        
        int n = nums.size(), ans = 0;
        for (int i=n-2; i>=0; i--){
            if (nums[i] > nums[i+1]){
                nums[i] = nums[i] / getGPD(nums[i]);
                if (nums[i] > nums[i+1]) return -1;
                else ans++;
            }
        }

        return ans;
    }
};