class Solution {
public:
    string losingPlayer(int x, int y) {
        y = y/4;
        if (min(x,y) % 2 == 0) return "Bob";
        return "Alice";
    }
};