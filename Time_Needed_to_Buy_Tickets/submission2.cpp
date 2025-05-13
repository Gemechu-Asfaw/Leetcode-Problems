class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        queue<pair<int,int>> q1;
        int ans = 0, n = tickets.size();

        for (int i=0; i<n; i++){
            q1.push({i, tickets[i]});
        }

        while (true){
            pair<int,int> front = q1.front();
            q1.pop();
            ans++;
            front.second--;
            if (front.second==0 && front.first==k){
                break;
            } else if (front.second>0){
                q1.push(front);
            }
        }

        return ans;
    }
};