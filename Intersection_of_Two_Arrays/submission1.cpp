class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();

        while (i<n && j<m){

            if (nums1[i] == nums2[j]){
                if (ans.empty() || ans[ans.size()-1]!=nums1[i]){
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            } else if (nums1[i] < nums2[j]){
                i++;
            } else {
                j++;
            }
        }

        return ans;
    }
};