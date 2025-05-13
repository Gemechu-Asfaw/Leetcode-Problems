class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0;
        long long ans = 0;
        unordered_map<int, int> occurrence;
        int total = 0;

        while (j<n){
            occurrence[nums[j]]++;
            total = total + (occurrence[nums[j]] - 1);
            if (total >= k){
                ans = ans + n - j;
            }

            while (total >= k){
                total = total - (occurrence[nums[i]] - 1);
                occurrence[nums[i]]--;
                i++;
                if (total >= k){
                    ans = ans + n - j;
                }
            }

            j++;
        }

        return ans;
    }
};