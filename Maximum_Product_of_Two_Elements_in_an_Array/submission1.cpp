class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int first = 0, second = 1;
        int n = nums.size();

        if (nums[second] > nums[first]){
            swap(first,second);
        }

        for (int index=2; index<n; index++){
            if (nums[index] >= nums[first]){
                second = first;
                first = index;
            }
            else if (nums[index] >= nums[second]){
                second = index;
            }
        }

        int ans = (nums[first]-1)*(nums[second]-1);
        return ans;
    }
};