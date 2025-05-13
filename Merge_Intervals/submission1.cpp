class Solution {
public:
    bool static cmp(vector<int> &a, vector<int> &b){
        return (a[0] < b[0]) || (a[0]==b[0] && a[1]<b[1]);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size(), i = 0;

        sort(intervals.begin(), intervals.end(), cmp);

        while (i<n){
            int startingPoint = intervals[i][0], endingPoint = intervals[i][1];
            int j = i+1;

            while (j<n && intervals[j][0]<=endingPoint){
                endingPoint = max(endingPoint, intervals[j][1]);
                j++;
            }

            ans.push_back({startingPoint, endingPoint});
            i = j;
        }

        return ans;
    }
};