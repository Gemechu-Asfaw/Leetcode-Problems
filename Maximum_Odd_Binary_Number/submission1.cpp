class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int index = 0, n = s.size();

        for (int i=0; i<n; i++){
            if (s[i]=='1'){
                swap(s[i], s[index]);
                index++;
            }
        }

        swap(s[index-1], s[n-1]);
        return s;
    }
};