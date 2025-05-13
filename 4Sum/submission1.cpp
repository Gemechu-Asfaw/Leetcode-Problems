class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i=0; i<n; i++){
            if (i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            for (int j=i+3; j<n; j++){
                if (j+1<n && nums[j]==nums[j+1]){
                    continue;
                }
                int k = i+1, l = j-1;
                while (k<l){
                    long sum = (long)nums[i] + nums[j] + nums[k] + nums[l];
                    // cout << nums[i] << " " << nums[k] << " " << nums[l] << " " << nums[j] << endl;
                    if (sum == (long)target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while (k<l && nums[k]==nums[k-1]){
                            k++;
                        }
                        while (k<l && nums[l]==nums[l+1]){
                            l--;
                        }
                    } else if (sum < (long)target){
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }

        return ans;
    }
};