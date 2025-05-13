class Solution {
public:
    void dfs(vector<vector<int>> &adjList, vector<bool> &visited, int node, vector<int> &component){
        if (!visited[node]){
            visited[node] = true;
            component.push_back(node);

            for (int neighbour : adjList[node]){
                dfs(adjList, visited, neighbour, component);
            }
        }
    }

    bool isCompleteComponent(vector<int> &component, vector<vector<int>> &adjList){
        int componentSize = component.size();
        for (int element : component){
            if (adjList[element].size() != componentSize-1){
                return false;
            }
        }

        return true;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);

        for (auto edge : edges){
            int x = edge[0], y = edge[1];
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }

        for (int i=0; i<n; i++){
            vector<int> component;
            dfs(adjList, visited, i, component);
            if (component.size() && isCompleteComponent(component, adjList)){
                ans++;
            }
        }

        return ans;
    }
};