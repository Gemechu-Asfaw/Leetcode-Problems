class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        int ans = 0, n = heights.size();

        for (int i=0; i<n; i++){
            heights[i] = heights[i]*101 + i;
        }

        sort(heights.begin(), heights.end());

        for (int i=0; i<n; i++){
            if (heights[heights[i]%101]/101 != heights[i]/101){
                ans++;
            }
        }

        return ans;
    }
};