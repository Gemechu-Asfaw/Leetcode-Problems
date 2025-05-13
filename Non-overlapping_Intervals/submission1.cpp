class Solution {
private:
    static bool cmp (vector<int> a, vector<int> b){
        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int count = 0, n = intervals.size(), endTime = INT_MIN;
        sort(intervals.begin(), intervals.end(), cmp);

        for (int i=0; i<n; i++){
            if (intervals[i][0] >= endTime){
                endTime = intervals[i][1];
                count++;
            }
        }

        return n - count;
    }
};