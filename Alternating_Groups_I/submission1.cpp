class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0, n = colors.size();
        for (int i=0; i<n; i++){
            if (colors[i]!=colors[(n+i-1)%n] && colors[i]!=colors[(i+1)%n]) ans++;
        }
        return ans;
    }
};