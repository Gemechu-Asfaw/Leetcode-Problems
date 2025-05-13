class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.first < b.first;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        
        int m = rectangles.size();
        vector<pair<int, int>> horizontal(m), vertical(m);

        for (int i=0; i<m; i++){
            horizontal[i] = {rectangles[i][0], rectangles[i][2]};
            vertical[i] = {rectangles[i][1], rectangles[i][3]};
        }

        sort(horizontal.begin(), horizontal.end(), cmp);
        sort(vertical.begin(), vertical.end(), cmp);

        int lastHorizontal = horizontal[0].second-1, lastVertical = vertical[0].second-1, horizontalBuffer = 0, verticalBuffer = 0;

        for (int i=1; i<m; i++){
            if ((horizontal[i].first - lastHorizontal) >= 1){
                horizontalBuffer++;
            }

            if ((vertical[i].first - lastVertical) >= 1){
                verticalBuffer++;
            }

            lastHorizontal = max(lastHorizontal, horizontal[i].second-1);
            lastVertical = max(lastVertical, vertical[i].second-1);
        }

        return (horizontalBuffer>=2) || (verticalBuffer >= 2);
    }
};