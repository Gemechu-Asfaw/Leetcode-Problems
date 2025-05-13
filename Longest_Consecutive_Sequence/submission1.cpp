class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        for (int element : numSet){
            if (numSet.find(element-1) == numSet.end()) {
                int nextElement = element+1;
                while (numSet.find(nextElement) != numSet.end()) nextElement++;
                ans = max(ans, nextElement-element);
            }
        }

        return ans;
    }
};