class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int, int> numberToColor, colorCount;
        vector<int> ans;

        for (int i=0; i<n; i++){
            int ball = queries[i][0], color = queries[i][1];
            if (numberToColor.find(ball) != numberToColor.end()){
                int previousColor = numberToColor[ball];
                colorCount[previousColor]--;
                if (colorCount[previousColor] == 0){
                    colorCount.erase(previousColor);
                }
            }
            numberToColor[ball] = color;
            colorCount[color]++;
            ans.push_back(colorCount.size());
        }

        return ans;
    }
};