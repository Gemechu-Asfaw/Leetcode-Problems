class Solution {
public:
    string sortSentence(string s) {
        
        int n = s.size(), count = 0;
        string temp, ans;
        vector<string> words(10, "");

        for (int i=0; i<=n; i++){
            if (i==n || s[i]==' '){
                int position = temp[temp.size()-1] - '0';
                temp.pop_back();
                words[position].append(temp);
                temp.clear();
                count++;
            } else {
                temp.push_back(s[i]);
            }
        }

        for (int i=1; i<=count; i++){
            ans.append(words[i]);
            ans.push_back(' ');
        }

        ans.pop_back();
        return ans;
    }
};