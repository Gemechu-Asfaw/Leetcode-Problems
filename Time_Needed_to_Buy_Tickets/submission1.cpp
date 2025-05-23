class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int ans = 0, n = tickets.size();
        for (int i=0; i<n; i++){
            if (i<=k){
                ans = ans + min(tickets[i], tickets[k]);
            } else {
                ans = ans + min(tickets[i], tickets[k]-1);
            }
        }

        return ans;
    }
};