class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> present;
        for (int num : nums){
            if (present.find(num)==present.end()){
                present.insert(num);
            } else {
                present.erase(num);
            }
        }
        return present.size()==0;
    }
};