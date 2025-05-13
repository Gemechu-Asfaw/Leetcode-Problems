class Solution {
public:
    void dfs(vector<vector<int>> &adjList, int node, vector<bool> &visited, vector<int> &temp){
        if (!visited[node]){
            temp.push_back(node);
            visited[node] = true;
            
            for (auto neighbour : adjList[node]){
                dfs(adjList, neighbour, visited, temp);
            }
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

        int componentIndex = 0, q = query.size();
        vector<bool> visited(n, false);
        unordered_map<int, int> mapping;
        vector<vector<int>> adjList(n);
        vector<int> components;
        vector<int> ans(q, 0);

        for (auto edge : edges){
            int x = edge[0], y = edge[1];
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }

        for (int i=0; i<n; i++){
            vector<int> temp;
            dfs(adjList, i, visited, temp);

            for (auto node : temp){
                mapping[node] = componentIndex;
            }

            componentIndex++;
        }

        // vector<int> components(componentIndex, -1);
        components.resize(componentIndex);
        fill(components.begin(), components.end(), -1);

        // for (auto x : mapping){
        //     if (components[x.second] == -1){
        //         components[x.second] = x.first;
        //     } else {
        //         components[x.second] = components[x.second] & x.first;
        //     }
        // }

        for (auto edge : edges){
            int x = edge[0], y = edge[1], value = edge[2];
            if (components[mapping[x]] == -1){
                components[mapping[x]] = value;
            } else {
                components[mapping[x]] = components[mapping[x]] & value;
            }
        }

        for (int i=0; i<q; i++){
            int startingNode = query[i][0], endingNode = query[i][1];
            if (mapping[startingNode] == mapping[endingNode]){
                ans[i] = components[mapping[startingNode]];
            } else {
                ans[i] = -1;
            }
        }

        return ans;
    }
};