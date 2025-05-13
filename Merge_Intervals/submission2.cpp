class Solution {
public:
    pair<int,int> dfs(int i, vector<vector<int>> &adj, vector<bool> &visited, vector<vector<int>> &intervals){
        pair<int, int> minimaxi = {intervals[i][0], intervals[i][1]};
        for (auto j : adj[i]){
            if (!visited[j]){
                visited[j] = true;
                pair<int,int> temp = dfs(j, adj, visited, intervals);
                minimaxi.first = min(minimaxi.first, temp.first);
                minimaxi.second = max(minimaxi.second, temp.second);
            }
        }
        return minimaxi;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size(), row = intervals.size(), col = intervals[0].size();
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        vector<vector<int>> ans;

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if ( i!=j && ((intervals[i][0]>=intervals[j][0] && intervals[i][0]<=intervals[j][1]) || (intervals[i][1]>=intervals[j][0] && intervals[i][1]<=intervals[j][1])) ){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for (int i=0; i<n; i++){
            if (!visited[i]){
                visited[i] = true;
                pair<int,int> interval = dfs(i, adj, visited, intervals);
                ans.push_back({interval.first, interval.second});
            }
        }

        return ans;
    }
};