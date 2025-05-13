class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int size = nums.size();
        int ans = 0;
        unordered_map<int,int> mapping;

        for (int i=0; i<size; i++){
            int element = nums[i];
            ans = ans + mapping[element];
            mapping[element]++;
        }

        return ans;
    }
};