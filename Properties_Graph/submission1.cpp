class Solution {
public:
    void dfs(vector<vector<int>> &adjList, int node, vector<bool> &visited){
        if (!visited[node]){
            visited[node] = true;
            for (auto neighbour : adjList[node]){
                dfs(adjList, neighbour, visited);
            }
        }
    }

    int intersect(vector<int>& a, vector<int> &b, int m){

        // unordered_set<int> first, second;
        unordered_set<int> common;
        int count = 0, i = 0, j = 0;

        while (i<m && j<m){
            if (a[i] == b[j]){
                count++;
                i++;
                j++;

                while (i<m && a[i] == a[i-1]){
                    i++;
                }

                while (j<m && b[j] == b[j-1]){
                    j++;
                }
            } else if (a[i] < b[j]){
                i++;
                while (i<m && a[i] == a[i-1]){
                    i++;
                }
            } else {
                j++;
                while (j<m && b[j] == b[j-1]){
                    j++;
                }
            }
        }

        // for (int x=0; x<m; x++){
        //     first.insert(a[x]);
        //     second.insert(b[x]);
        // }

        // for (auto x : first){
        //     if (second.find(x) != second.end()){
        //         count++;
        //     }
        // }

        return count;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size(), m = properties[0].size();
        int components = 0;
        vector<bool> visited(n, false);
        vector<vector<int>> adjList(n);

        for (int i=0; i<n; i++){
            sort(properties[i].begin(), properties[i].end());
        }

        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if (intersect(properties[i], properties[j], m) >= k){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        for (int i=0; i<n; i++){

            // for (int i=0; i<n; i++){
            //     cout << visited[i] << " ";
            // }
            // cout << endl;
            
            if (!visited[i]){
                components++;
                dfs(adjList, i, visited);
            }
        }

        return components;
    }
};