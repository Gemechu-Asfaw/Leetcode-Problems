class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), i = 0, count = 0;

        while (n-i>=3){
            if (nums[i] == 0){
                count++;
                for (int j=i; j<i+3; j++){
                    if (nums[j] == 0){
                        nums[j] = 1;
                    } else {
                        nums[j] = 0;
                    }
                }
            }
            i++;
        }

        for (int i=0; i<n; i++){
            if (nums[i] == 0){
                return -1;
            }
        }

        return count;
    }
};