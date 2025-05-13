class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int>> temp;
        int n = nums.size(), s=0, e=n-1;
        vector<int> ans = {-1,-1};

        for (int i=0; i<n; i++){
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());

        while (s < e){
            int currSum = temp[s].first + temp[e].first;
            if (currSum == target){
                ans[0] = temp[s].second;
                ans[1] = temp[e].second;
                break;
            } else if (currSum > target){
                e--;
            } else {
                s++;
            }
        }

        return ans;
    }
};