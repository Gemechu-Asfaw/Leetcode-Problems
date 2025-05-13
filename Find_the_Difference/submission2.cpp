class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int occurance[26] = {0};
        int size = s.length();

        for (int i=0; i<=size; i++){
            
            if (i!=size){
                occurance[s[i]-97]--;
            }
            occurance[t[i]-97]++;
        }

        char ans;
        for (int i=0; i<26; i++){
            if (occurance[i]==1){
                ans = i+97;
                break;
            }
        }

        return ans;
    }
};