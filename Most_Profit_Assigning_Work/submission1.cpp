class Solution {
public:

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        int ans = 0, n = difficulty.size(), m = worker.size();
        int i = m-1, j = n-1;
        vector<pair<int,int>> temp;

        for (int i=0; i<n; i++){
            temp.push_back({profit[i], difficulty[i]});
        }

        sort(temp.begin(), temp.end());
        sort(worker.begin(), worker.end());

        while (j >= 0 && i>=0){

            while (j>=0 && temp[j].second > worker[i]){
                j--;
            }

            if (j>=0){
                ans = ans + temp[j].first;
                i--;
            }
        }

        return ans;
    }
};