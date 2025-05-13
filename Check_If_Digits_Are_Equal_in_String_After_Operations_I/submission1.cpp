class Solution {
public:
    bool hasSameDigits(string s) {
        int size = s.size();
        while (size > 2){
            string newS = "";
            for (int i=0; i<size-1; i++){
                char character = (s[i] - 48 + s[i+1] - 48) % 10 + '0';
                newS.push_back(character);
            }

            for (int i=0; i<size-1; i++){
                s[i] = newS[i];
            }
            size--;
        }

        return s[0]==s[1];
    }
};