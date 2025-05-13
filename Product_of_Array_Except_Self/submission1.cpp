class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size(), prefix = 1, suffix = 1;
        vector<int> prefixProduct(n,0);
        vector<int> suffixProduct(n,0);

        for (int i=0; i<n; i++){
            prefix = prefix*nums[i];
            prefixProduct[i] = prefix;
        }

        for (int i=n-1; i>=0; i--){
            suffix = suffix*nums[i];
            suffixProduct[i] = suffix;
        }

        for (int i=0; i<n; i++){
            
            nums[i] = 1;

            if (i>0){
                nums[i] = nums[i] * prefixProduct[i-1];
            }

            if (i < n-1){
                nums[i] = nums[i] * suffixProduct[i+1];
            }
        }

        return nums;
    }
};