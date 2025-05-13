class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        
        // Initializing dq
        for (int i=0; i<k; i++){
            if (dq.empty() || dq.back()==nums[i]-1){
                dq.push_back(nums[i]);
            } else {
                while (!dq.empty()){
                    dq.pop_back();
                }
                dq.push_back(nums[i]);
            }
        }
        
        ans.push_back(dq.size()>=k ? dq.back() : -1);

        for (int i=k; i<n; i++){
            if (dq.empty() || dq.back()==nums[i]-1){
                dq.push_back(nums[i]);
            } else {
                while (!dq.empty()){
                    dq.pop_back();
                }
                dq.push_back(nums[i]);
            }
            ans.push_back(dq.size()>=k ? dq.back() : -1);
        }

        return ans;
    }
};