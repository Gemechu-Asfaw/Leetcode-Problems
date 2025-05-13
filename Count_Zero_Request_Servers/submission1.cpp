class Solution {
public:
    bool static cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }

    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        int m = logs.size(), q = queries.size();
        vector<int> ans(q, 0);
        unordered_map<int, int> occurrence;
        vector<pair<int, int>> modifiedQueries(q);
        
        for (int i=0; i<q; i++){
            modifiedQueries[i] = {queries[i], i};
        }

        sort(logs.begin(), logs.end(), cmp);
        sort(modifiedQueries.begin(), modifiedQueries.end());

        int i = 0, j = 0;
        for (auto query : modifiedQueries){
            int startTime = query.first-x, endTime = query.first;
            while (j<m && logs[j][1]<=endTime){
                occurrence[logs[j][0]]++;
                j++;
            }

            while (i<m && logs[i][1]<startTime){
                occurrence[logs[i][0]]--;
                if (occurrence[logs[i][0]] == 0){
                    occurrence.erase(logs[i][0]);
                }
                i++;
            }

            ans[query.second] = n-occurrence.size();
        }

        return ans;
    }
};