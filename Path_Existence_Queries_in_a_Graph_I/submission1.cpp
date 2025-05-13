class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        unordered_map<int, int> components;
        int componentNo = 1, last = 0, q = queries.size();
        vector<bool> ans(q, false);

        for (int i=0; i<n; i++){
            if (i==n-1 || abs(nums[i+1]-nums[i])>maxDiff){
                for (int j=last; j<=i; j++){
                    components[j] = componentNo;
                }
                componentNo++;
                last = i+1;
            }
        }

        for (int i=0; i<q; i++){
            int u = queries[i][0], v = queries[i][1];
            if (components[u] == components[v]){
                ans[i] = true;
            } else {
                ans[i] = false;
            }
        }

        return ans;
    }
};