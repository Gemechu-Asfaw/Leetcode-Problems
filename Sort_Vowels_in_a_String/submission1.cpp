class Solution {
public:
    bool isVowel(char x){
        vector<char> vowels = {'A', 'E', 'I', 'O', 'U'};
        for (char vowel : vowels){
            if (x == vowel || x== vowel+32) return true;
        }
        return false;
    }

    string sortVowels(string s) {
        int n = s.size();
        map<char, int> mapping;

        for (int i=0; i<n; i++){
            if (isVowel(s[i])){
                mapping[s[i]]++;
            }
        }

        for (int i=0; i<n; i++){
            if (isVowel(s[i])){
                s[i] = mapping.begin()->first;
                mapping.begin()->second--;
                if (mapping.begin()->second == 0) mapping.erase(mapping.begin()->first);
            }
        }

        return s;
    }
};