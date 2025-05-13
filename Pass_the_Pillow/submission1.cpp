class Solution {
public:
    int passThePillow(int n, int time) {
        int cycleNo = time/(n-1), cyclePos = time%(n-1);
        return (cycleNo%2==0) ? 1+cyclePos : n-cyclePos;
    }
};