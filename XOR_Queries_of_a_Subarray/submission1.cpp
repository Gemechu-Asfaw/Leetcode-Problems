class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), q = queries.size();
        vector<int> prefixXor(n, arr[0]);
        vector<int> ans;

        for (int i=1; i<n; i++){
            prefixXor[i] = prefixXor[i-1]^arr[i];
        }

        for (int i=0; i<q; i++){
            int left = queries[i][0], right = queries[i][1];
            int element = prefixXor[right];
            if (left != 0) element = element ^ prefixXor[left-1];
            ans.push_back(element);
        }

        return ans;
    }
};