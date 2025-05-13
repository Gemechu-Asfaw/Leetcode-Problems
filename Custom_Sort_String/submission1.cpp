class Solution {
public:

    string customSortString(string order, string s) {
        
        vector<int> priority(26, 0);
        int n = s.size();

        for (int i=0; i<order.size(); i++){
            priority[order[i]-'a'] = i+1;
        }

        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if (priority[s[j]-'a'] != 0 && priority[s[i]-'a'] > priority[s[j]-'a']){
                    swap(s[i], s[j]);
                }
            }
        }

        return s;
    }
};