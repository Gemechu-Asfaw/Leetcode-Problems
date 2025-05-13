class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> presence;

        for (int i=n-1; i>=0; i--){
            if (presence.find(nums[i]) != presence.end()){
                return (i+1)/3 + min((i+1)%3, 1);
            } else {
                presence.insert(nums[i]);
            }
        }

        return 0;
    }
};