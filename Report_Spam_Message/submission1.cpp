class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string, int> map;
        int count = 0;

        for (string word : message){
            map[word]++;
        }

        for (string word : bannedWords){
            if (map.find(word) != map.end()){
                count = count + map[word];
                map.erase(word);
                if (count >= 2) return true;
            }
        }

        return false;
    }
};