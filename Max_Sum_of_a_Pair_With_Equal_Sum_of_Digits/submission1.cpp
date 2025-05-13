class Solution {
public:
    int getDigitSum(int n){
        int sum = 0;
        while (n){
            sum = sum + n%10;
            n = n/10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int ans = -1, n = nums.size();
        unordered_map<int, int> digitToMaxElement;
        for (int i=0; i<n; i++){
            if (digitToMaxElement.find(getDigitSum(nums[i])) == digitToMaxElement.end()){
                digitToMaxElement[getDigitSum(nums[i])] = nums[i];
            } else {
                ans = max(ans, nums[i]+digitToMaxElement[getDigitSum(nums[i])]);
                digitToMaxElement[getDigitSum(nums[i])] = max(digitToMaxElement[getDigitSum(nums[i])], nums[i]);
            }
        }

        return ans;
    }
};