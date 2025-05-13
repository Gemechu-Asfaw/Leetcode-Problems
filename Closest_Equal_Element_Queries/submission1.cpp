class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), q = queries.size();
        unordered_map<int, int> lastOccurrence;
        unordered_map<int, int> firstOccurrence;
        vector<int> gap(n, INT_MAX);
        vector<int> ans(q, -1);

        for (int i=0; i<n; i++){
            if (lastOccurrence.find(nums[i])==lastOccurrence.end()){
                lastOccurrence[nums[i]] = firstOccurrence[nums[i]] = i;
            } else {
                int currentGap = min(i-lastOccurrence[nums[i]], (n-i+firstOccurrence[nums[i]]));
                gap[i] = currentGap;
                gap[lastOccurrence[nums[i]]] = min(i-lastOccurrence[nums[i]], gap[lastOccurrence[nums[i]]]);
                gap[firstOccurrence[nums[i]]] = min(n-i+firstOccurrence[nums[i]], gap[firstOccurrence[nums[i]]]);
                lastOccurrence[nums[i]] = i;
            }
        }

        // for (int i=0; i<n; i++){
        //     cout << gap[i] << " ";
        // }
        // cout << endl;

        for (int i=0; i<q; i++){
            ans[i] = gap[queries[i]]==INT_MAX ? -1 : gap[queries[i]];
        }

        return ans;
    }
};