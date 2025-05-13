class cmp{
    public:
        bool operator()(pair<long long, long long> a, pair<long long, long long> b){
            return a.first*a.second*(a.second+1) > b.first*b.second*(b.second+1);
        }
};

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long ans = 0, n = workerTimes.size();
        priority_queue<pair<long long, long long>, vector<pair<long long,long long>>, cmp> pq;

        for (int i=0; i<n; i++){
            pq.push({workerTimes[i], 1});
        }

        while (mountainHeight--){
            pair<long long, long long> top = pq.top();
            long long time = top.first, itr = top.second;
            // cout << time << " " << itr << endl;
            pq.pop();
            ans = max(ans, time*(itr*(itr+1))/2);
            pq.push({time, itr+1});
        }

        return ans;
    }
};