class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int i = 0, j = 0, n = s.size(), ans = 0;
        unordered_map<int,int> mapping;
        
        while (j < n){
            
            mapping[s[j]]++;
            if (mapping[s[j]] <= 2){
                ans = max(ans, j-i+1);   
            }
            
            while (mapping[s[j]]>2){
                mapping[s[i]]--;
                i++;
            }
                           
            j++;
        }
                           
        return ans;
    }
};