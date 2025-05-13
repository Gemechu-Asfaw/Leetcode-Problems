class Solution {
public:
    bool isIncreasing(vector<int>& nums){
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            if (nums[i] > nums[i+1]){
                return false;
            }
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0, n = nums.size();
        while (!isIncreasing(nums)){
            
            ans++;
            int index = 0, shortest = nums[0]+nums[1];
            for (int i=1; i<nums.size()-1; i++){
                if (nums[i]+nums[i+1] < shortest){
                    shortest = nums[i]+nums[i+1];
                    index = i;
                }
            }

            nums[index] = nums[index] + nums[index+1];
            for (int i=index+1; i<nums.size()-1; i++){
                nums[i] = nums[i+1];
            }

            nums.pop_back();
        }

        return ans;
    }
};