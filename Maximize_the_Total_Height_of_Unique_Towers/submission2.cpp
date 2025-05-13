class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        long long sum = 0;
        int largest = INT_MIN, n = maximumHeight.size(), top;
        priority_queue<int> pq;

        for (int i=0; i<n; i++){
            pq.push(maximumHeight[i]);
            largest = max(largest, maximumHeight[i]);
        }

        while (!pq.empty()){
            if (largest <= 0) return -1;
            top = pq.top();
            pq.pop();
            largest = min(largest, top);
            sum = sum + largest;
            largest--;
        }

        return sum;
    }
};