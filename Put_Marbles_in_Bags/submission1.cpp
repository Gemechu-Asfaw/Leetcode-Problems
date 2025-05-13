class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long maxScore = 0, minScore = 0;
        int n = weights.size();
        priority_queue<int> maxi;
        priority_queue<int, vector<int>, greater<int>> mini;

        for (int i=0; i<n-1; i++){
            maxi.push(weights[i]+weights[i+1]);
            mini.push(weights[i]+weights[i+1]);
        }

        for (int i=0; i<k-1; i++){
            maxScore = maxScore + maxi.top();
            minScore = minScore + mini.top();
            mini.pop();
            maxi.pop();
        }

        return maxScore-minScore;
    }
};