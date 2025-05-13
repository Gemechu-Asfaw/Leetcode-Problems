class Solution {
public:
    bool isVowel(char x){
        return (x=='a' || x=='e' || x=='i' || x=='o' || x=='u');
    }

    bool isVowelMissing(unordered_map<char, bool> mapping){
        if (mapping.size() < 5) return true;
        for (auto i:mapping){
            if (i.second == 0) return true;
        }
        return false;
    }

    int countOfSubstrings(string word, int k) {
        int n = word.size(), ans = 0;

        for (int i=0; i<n; i++){
            unordered_map<char, bool> mapping;
            int consonants = 0;
            for (int j=i; j<n; j++){
                if (isVowel(word[j])){
                    mapping[word[j]] = true; 
                } else {
                    consonants++;
                }

                if (!isVowelMissing(mapping) && consonants==k) ans++;
                else if (consonants > k) break;

            }
        }

        return ans;
    }
};