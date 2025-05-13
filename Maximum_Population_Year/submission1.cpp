class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        
        map<int,int> population;
        for (int i=0; i<logs.size(); i++){
            int birth = logs[i][0], death = logs[i][1];
            for (int j=birth; j<death; j++){
                population[j]++;
            }
        }

        int maxyear = population.begin()->first;
        for (auto element: population){
            if (element.second > population[maxyear]){
                maxyear = element.first;
            }
        }

        return maxyear;
    }
};