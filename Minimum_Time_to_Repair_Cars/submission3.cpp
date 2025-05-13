class cmp{
public:
    bool operator()(pair<int, long long> &a, pair<int, long long> &b){
        return a.first*a.second*a.second > b.first*b.second*b.second;
    }
};

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, cmp> minHeap;
        int n = ranks.size();
        long long ans = 0;

        for (int i=0; i<n; i++){
            minHeap.push({ranks[i], 1});
        }

        for (int i=0; i<cars; i++){
            pair<int, long long> top = minHeap.top();
            minHeap.pop();
            ans = max(ans, top.first*top.second*top.second);
            minHeap.push({top.first, top.second+1});
        }

        return ans;
    }
};