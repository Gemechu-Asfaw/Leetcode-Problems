class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_map<string, vector<string>> graph;
        unordered_set<string> rawIngredients;
        unordered_map<string, int> requirements;
        unordered_set<string> createdRecipes;
        vector<string> ans;
        queue<string> q;

         // Pushing all raw ingredients to queue
        for (int i=0; i<supplies.size(); i++){
            rawIngredients.insert(supplies[i]); 
            q.push(supplies[i]);
        }

        // Building graph
        for (int i=0; i<recipes.size(); i++){
            requirements[recipes[i]] = ingredients[i].size();
            for (int j=0; j<ingredients[i].size(); j++){
                graph[ingredients[i][j]].push_back(recipes[i]);
            }
        }

        // Topological sort process
        while (!q.empty()){
            string top = q.front();
            q.pop();
            for (auto x : graph[top]){
                requirements[x]--;
                if (requirements[x] == 0){
                    q.push(x);
                    createdRecipes.insert(x);
                }
            }
        }

        for (auto x : createdRecipes){
            ans.push_back(x);
        }

        return ans;
    }
};