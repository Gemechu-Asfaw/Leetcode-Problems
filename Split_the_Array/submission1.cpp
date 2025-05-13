class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        
        unordered_map<int, int> occurance;
        for (int num : nums){
            occurance[num]++;
        }
        
        for (auto i : occurance){
            if (i.second > 2){
                return false;
            }
        }
        
        return true;
    }
};