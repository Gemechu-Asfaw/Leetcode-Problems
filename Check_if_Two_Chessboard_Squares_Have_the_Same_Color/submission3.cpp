class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int x1 = coordinate1[0] - 'a', y1 = coordinate1[1] - '0', x2 = coordinate2[0] - 'a', y2 = coordinate2[1] - '0';
        int color1 = 0, color2 = 0;
        if ((x1%2==0 && y1%2!=0) || (x1%2!=0 && y1%2==0)) color1 = 1;
        if ((x2%2==0 && y2%2!=0) || (x2%2!=0 && y2%2==0)) color2 = 1;
        return color1==color2;
    }
};