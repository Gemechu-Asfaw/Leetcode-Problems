class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int x1 = coordinate1[0] - 'a', y1 = coordinate1[1] - '1', x2 = coordinate2[0] - 'a', y2 = coordinate2[1] - '1';
        return (x1 + ((y1%2==0) ? 1 : 0))%2 == (x2 + ((y2%2==0) ? 1 : 0))%2;
    }
};