class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int i = 0, n = intervals.size(), starting = newInterval[0], ending = newInterval[1];
        vector<vector<int>> ans;

        // Left side of the inserted or merged intervals
        while (i < n && newInterval[0] > intervals[i][1]){
            ans.push_back(intervals[i]);
            i++;
        }

        // Interval that is going to be inserted or merged 
        while (i < n && newInterval[1] >= intervals[i][0]){
            starting = min(starting, intervals[i][0]);
            ending = max(ending, intervals[i][1]);
            i++;
        }

        ans.push_back({starting, ending});

        // Right side of the inserted or merged intervals
        while (i < n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};