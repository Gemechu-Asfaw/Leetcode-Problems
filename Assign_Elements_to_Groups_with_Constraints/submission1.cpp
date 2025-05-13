class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = groups.size();
        vector<int> assigned(n, INT_MAX);
        unordered_map<int, int> factors;

        for (int i=0; i<elements.size(); i++){
            if (factors.find(elements[i]) == factors.end()){
                factors[elements[i]] = i;
            }
        }

        for (int i=0; i<n; i++){
            for (int j=1; j*j<=groups[i]; j++){
                if (groups[i]%j == 0){
                    if (factors.find(j)!=factors.end()) assigned[i] = min(assigned[i], factors[j]);
                    if (factors.find(groups[i]/j)!=factors.end()) assigned[i] = min(assigned[i], factors[groups[i]/j]);
                }
            }
        }

        for (int i=0; i<n; i++){
            if (assigned[i] == INT_MAX){
                assigned[i] = -1;
            }
        }

        return assigned;
    }
};