class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n = queries.size();
        vector<int> ans;
        priority_queue<int> pq;

        for (int i=0; i<n; i++){
            int x = queries[i][0], y = queries[i][1];
            int distance = abs(x) + abs(y);
            if (pq.size() < k){
                pq.push(distance);
            } else if (distance < pq.top()){
                pq.pop();
                pq.push(distance);
            }
            ans.push_back(pq.size()>=k ? pq.top() : -1);
        }

        return ans;
    }
};