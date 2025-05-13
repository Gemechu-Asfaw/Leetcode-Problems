class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int size = s.length();
        int occurance[26] = {0};

        for (int i=0; i<=size; i++){

            if (i!=size){
                occurance[s[i]-97]--;
            }
            occurance[t[i]-97]++;
        }

        char character;
        for (int i=0; i<26; i++){
            if (occurance[i]==1){
                character = i+'a';
                break;
            }
        }

        return character;
    }
};