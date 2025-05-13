class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0, maxi = 0, n = s.size();
        for (int i=0; i<n; i++){
            if (s[i] == '('){
                mini++;
                maxi++;
            } else if (s[i] == ')'){
                maxi = maxi - 1;
                mini = max(0, mini-1);
                if (maxi < 0) return false;
            } else {
                maxi++;
                mini = max(0,mini-1);
            }
        }

        return mini==0;
    }
};