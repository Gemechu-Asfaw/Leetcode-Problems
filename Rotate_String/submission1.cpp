class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        string doubleString = s + s;
        return doubleString.find(goal) < doubleString.length();
    }
};