class cmp {
    public:
       bool operator()(pair<int, int> a, pair<int, int> b){
           return a.second < b.second || (a.second==b.second && a.first < b.first);
       }
};

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        int n = nums.size();
        vector<int> ans;

        for (int i=0; i<=n-k; i++){
            unordered_map<int, int> mapping;
            priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;
            int sum = 0, count = 0;

            for (int j=i; j<i+k; j++){
                mapping[nums[j]]++;
            }

            for (auto pair : mapping){
                pq.push({pair.first, pair.second});
            }

            while (count < x & !pq.empty()){
                pair<int, int> top = pq.top();
                pq.pop();
                count++;
                sum = sum + top.first*top.second;
            }

            ans.push_back(sum);
        }

        return ans;
    }
};