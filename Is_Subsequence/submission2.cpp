class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int size1 = s.length();
        int size2 = t.length();
        stack<int> s1;

        for (int i=0; i<size1; i++){
            s1.push(s[i]);
        }

        for (int i=size2-1; i>=0; i--){
            if (s1.empty()){
                break;
            }
            if (s1.top()==t[i]){
                s1.pop();
            }
        }

        if (s1.empty()){
            return true;
        }
        return false;

    }
};