class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        int n = s.size();
        for (int i=0; i<n; i++){
            bool flag = true;
            for (int j=0; j<n; j++){
                if (s[j] != goal[(i+j)%n]){
                    flag = false;
                    break;
                }
            }

            if (flag){
                return true;
            }
        }

        return false;
    }
};