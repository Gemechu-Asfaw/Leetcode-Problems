class Solution {
public:
    vector<string> stringSequence(string target) {

        int n = target.size(), i = 0;
        vector<string> ans;

        while (i < n){
            if (ans.size() == 0) {
                ans.push_back("a");
                if (target[0] == 'a'){
                    i++;
                }
            } else {
                string lastWord = ans[ans.size()-1];
                char lastCharacter = lastWord[lastWord.size()-1];
                if (i+1 == lastWord.size()){
                    string newWord = lastWord;
                    newWord[newWord.size()-1] = lastCharacter + 1;
                    ans.push_back(newWord);
                    if (lastCharacter + 1 == target[i]){
                        i++;
                    }
                } else {
                    ans.push_back(lastWord + "a");
                    if (target[i] == 'a'){
                        i++;
                    }
                }
            }
        }

        return ans;
    }
};