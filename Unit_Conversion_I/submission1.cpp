class Solution {
public:
    void dfs( vector<vector<pair<int, int>>> &adjList, vector<int> &ans, int node, long long value){
        
        ans[node] = value;
        for (auto neighbour : adjList[node]){
            int next = neighbour.first, weight = neighbour.second;
            dfs(adjList, ans, next, (value*weight)%int(1e9+7));
        }
        
    }
    
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size();
        vector<int> ans(n+1, 1);
        vector<vector<pair<int, int>>> adjList(n+1);

        for (int i=0; i<n; i++){
            int u = conversions[i][0], v = conversions[i][1], w = conversions[i][2];
            adjList[u].push_back({v, w});
        }

        dfs(adjList, ans, 0, 1);
        return ans;
    }
};