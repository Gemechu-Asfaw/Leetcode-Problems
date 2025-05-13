class Solution {
public:
    vector<int> partitionLabels(string s) {

        int n = s.size();
        vector<pair<int, int>> intervals;
        unordered_map<char, pair<int, int>> occurrence;
        vector<int> ans;

        for (int i=0; i<n; i++){
            if (occurrence.find(s[i]) == occurrence.end()){
                occurrence[s[i]] = {i, i};
            } else {
                occurrence[s[i]].second = i;
            }
        }

        for (auto x : occurrence){
            intervals.push_back(x.second);
        }

        sort(intervals.begin(), intervals.end());

        int i=0;
        while (i<intervals.size()){
            int j = i+1, first = intervals[i].first, last = intervals[i].second;
            while (j<intervals.size() && intervals[j].first < last){
                last = max(last, intervals[j].second);
                j++;
            }

            i = j;
            ans.push_back(last-first+1);
        }

        return ans;
    }
};