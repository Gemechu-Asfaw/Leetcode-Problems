class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i=0; i<n; i++){
            pq.push(nums[i]);
        }

        while (pq.size()>=2 && pq.top()<k){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            long long element = (long long)min(first, second)*2 + (long long)max(first, second);
            if (element <= INT_MAX) pq.push((int)element);
            ans++;
        }

        if (pq.size()==1 && pq.top()<k){
            ans++;
        }

        return ans;
    }
};