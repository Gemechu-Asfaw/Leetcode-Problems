class Solution {
public:
    void solve(vector<vector<int>> &isConnected, vector<bool> &visited, int node, int n){
        visited[node] = true;
        for (int i=0; i<n; i++){
            if (!visited[i] && isConnected[node][i]==1){
                solve(isConnected, visited, i, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool> visited(n, false);

        for (int i=0; i<n; i++){
            if (!visited[i]){
                ans++;
                solve(isConnected, visited, i, n);
            }
        }

        return ans;
    }
};