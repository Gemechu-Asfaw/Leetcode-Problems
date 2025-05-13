class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i=0; i<n; i++){
            int element = nums[i];
            bool flag = false;
            for (int j=1; j<=element; j++){
                if ((j | j+1) == element){
                    ans.push_back(j);
                    flag = true;
                    break;
                }
            }
            if (!flag) ans.push_back(-1);
        }

        return ans;
    }
};