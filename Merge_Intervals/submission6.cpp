class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return (a[0]<b[0]) || (a[0]==b[0] && a[1]<b[1]);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        int i = 0, endpoint, n = intervals.size();
        
        sort(intervals.begin(), intervals.end(), cmp);

        while (i<n){
            endpoint = intervals[i][1];
            int j = i+1;
            while (j<n && intervals[j][0] <= endpoint){
                endpoint = max(endpoint, intervals[j][1]);
                j++;
            }
            ans.push_back({intervals[i][0], endpoint});
            i = j;
        }

        return ans;
    }
};