class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        sort(apple.begin(), apple.end());
        sort(capacity.begin(), capacity.end());
        reverse(capacity.begin(), capacity.end());
        
        int i = 0, j = 0, n = apple.size(), m = capacity.size();
        
        while (i<n && j<m){
            if (capacity[j] >= apple[i]){
                capacity[j] = capacity[j] - apple[i];
                i++;
            } else {
                apple[i] = apple[i] - capacity[j];
                j++;
            }
        }
        
        return j+1;
    }
};