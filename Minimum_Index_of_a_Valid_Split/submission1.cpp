class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> forward, backward;
        vector<pair<int, int>> dominant(n);

        for (int i=0; i<n; i++){
            forward[nums[i]]++;
            if (forward[nums[i]] > (i+1)/2){
                dominant[i].first = nums[i];
            } else if (forward[dominant[i-1].first] > (i+1)/2){
                dominant[i].first = dominant[i-1].first;
            } else {
                dominant[i].first = -1;
            }
        }

        for (int i=n-1; i>=0; i--){
            backward[nums[i]]++;
            if (backward[nums[i]] > (n-i)/2){
                dominant[i].second = nums[i];
            } else if (backward[dominant[i+1].second] > (n-i)/2){
                dominant[i].second = dominant[i+1].second;
            } else {
                dominant[i].second = -1;
            }
        }

        for (int i=0; i<n; i++){
            cout << dominant[i].first << " ";
        }
        cout << endl;

        for (int i=0; i<n; i++){
            cout << dominant[i].second << " ";
        }
        cout << endl;

        for (int i=0; i<n-1; i++){
            if (dominant[i].first!=-1 && dominant[i].first == dominant[i+1].second){
                return i;
            }
        }

        return -1;
    }
};