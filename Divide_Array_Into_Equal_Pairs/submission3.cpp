class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> occurrence;
        for (int num : nums){
            occurrence[num]++;
        }

        for (auto x : occurrence){
            if (x.second & 1){
                return false;
            }
        }

        return true;
    }
};