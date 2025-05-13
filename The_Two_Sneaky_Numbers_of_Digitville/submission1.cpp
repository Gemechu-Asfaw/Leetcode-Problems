class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mapping;
        vector<int> ans;

        for (int element : nums){
            mapping[element]++;
            if (mapping[element] == 2) ans.push_back(element);
        }

        return ans;
    }
};