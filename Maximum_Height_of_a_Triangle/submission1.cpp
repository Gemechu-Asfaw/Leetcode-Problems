class Solution {
public:
    int solve(int x, int y){
        
        int step = 1;
        while (true) {
            if ((step % 2 == 0 && step > y) || (step%2 != 0 && step > x)){
                return step-1;
            } else {
                step % 2 == 0 ? y = y - step : x = x - step;
                step++;
            }
        }
    }
    
    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red, blue), solve(blue,red));
    }
};