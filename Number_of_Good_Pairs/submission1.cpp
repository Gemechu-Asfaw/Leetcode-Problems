class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int size = nums.size();
        int ans = 0;
        
        sort(nums.begin(),nums.end());

        int i=0;
        while (i<size){
            int j=i;
            while (j<size && nums[i]==nums[j]){
                j++;
            }
            int diff = j-i;
            ans = ans + diff*(diff-1)/2;
            i = j;
        }

        return ans;
    }
};