class Solution {

public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }

    int countDays(int days, vector<vector<int>>& meetings) {

        int lastUsed = 0, n = meetings.size(), ans = 0; 
        sort(meetings.begin(), meetings.end(), cmp);

        for (int i=0; i<n; i++){
            if (lastUsed < meetings[i][0]){
                ans = ans + meetings[i][0] - lastUsed - 1;
            }
            lastUsed = max(lastUsed, meetings[i][1]);
        }

        ans = ans + days - lastUsed;

        return ans;
    }
};