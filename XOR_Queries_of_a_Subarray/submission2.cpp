class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), q = queries.size();
        vector<int> leftXor(n, arr[0]);
        vector<int> rightXor(n, arr[n-1]);
        vector<int> ans;

        // Setting leftXor in first line
        // Setting rightXor in second line
        // Setting initializer in third line
        for (int i=1; i<n; i++){
            leftXor[i] = leftXor[i-1]^arr[i];
            rightXor[n-1-i] = rightXor[n-i]^arr[n-1-i];
        }

        // Setting answer
        for (int i=0; i<q; i++){
            int element = leftXor[n-1], left = queries[i][0], right = queries[i][1];
            if (left != 0) element = element ^ leftXor[left-1];
            if (right != n-1) element = element ^ rightXor[right+1];
            ans.push_back(element);
        }

        return ans;
    }
};