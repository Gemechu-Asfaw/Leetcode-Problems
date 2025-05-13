class Solution {
public:
    int twoPower(int n){
        int ans = 1;
        for (int i=0; i<n; i++){
            ans = ans*2;
        }
        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), range = twoPower(n);
        vector<vector<int>> ans;
        for (int i=0; i<range; i++){
            vector<int> temp;
            int j = n-1, value = 1;
            while (value<=i){
                if (i&value){
                    temp.push_back(nums[j]);
                }
                j--;
                value = value<<1;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};