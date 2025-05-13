class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int size1 = s.length();
        int size2 = t.length();
        queue<int> q1;

        for (int i=0; i<size1; i++){
            q1.push(s[i]);
        }

        for (int i=0; i<size2; i++){
            if (q1.empty()){
                break;
            }
            if (q1.front()==t[i]){
                q1.pop();
            }
        }

        if (q1.empty()){
            return true;
        }
        return false;

    }
};