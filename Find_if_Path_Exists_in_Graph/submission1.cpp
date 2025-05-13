class Solution {
public:
    bool solve(vector<vector<int>> &adj, vector<int> &visited, vector<bool> &dp, int current, int destination){

        if (current == destination){
            return true;
        } else if (dp[current] == false){
            return false;
        }

        visited[current] = true;
        bool isPossible = false;

        for (auto neighbour : adj[current]){
            if (!visited[neighbour]){
                isPossible = solve(adj, visited, dp, neighbour, destination);
                if (isPossible == true){
                    break;
                }
            }
        }

        return dp[current] = isPossible;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        vector<bool> dp(n, true);

        for (int i=0; i<edges.size(); i++){
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        return solve(adj, visited, dp, source, destination);
    }
};