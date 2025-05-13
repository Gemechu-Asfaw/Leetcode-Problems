class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long goodPairsCount = 0;

        for (int i=0; i<n; i++){
            nums[i] = nums[i] - i;
        }

        sort(nums.begin(), nums.end());

        int i, j = 0;
        for (i=1; i<n; i++){
            if (nums[i] != nums[i-1]){
                goodPairsCount = goodPairsCount + (long long)(i-j)*(i-j-1)/2;
                j = i;
            }
        }

        goodPairsCount = goodPairsCount + (long long)(i-j)*(i-j-1)/2;
        return (long long)n*(n-1)/2 - goodPairsCount;
    }
};