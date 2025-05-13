class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        int n = colors.size(), current = 0, ans = 0;
        // vector<int> alternateSum(n+k-1, 0);

        for (int i=0; i<k-1; i++){
            colors.push_back(colors[i]);
        }

        for (int i=0; i<n+k-2; i++){
            if (colors[i] == colors[i+1]){
                current = 0;
            } else {
                current++;
            }
            
            if (current >= k-1){
                ans++;
            }
        }

        return ans;
    }
};