class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> occurance;
        int n = s.size();
        int count = 0, odd = 0;

        for (int i=0; i<n; i++){
            occurance[s[i]]++;
        }

        for (auto character : occurance){
            count = count + (character.second/2)*2;
            if (character.second%2 == 1) odd = 1;
        }

        count = count + odd;
        return count;
    }
};