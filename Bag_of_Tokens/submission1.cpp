class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size()-1;
        int score = 0, highestScore = 0;

        while (i<=j){
            if (tokens[i] <= power){
                score++;
                highestScore = max(score,highestScore);
                power = power - tokens[i];
                i++;
            } else if (score>0) {
                score--;
                power = power + tokens[j];
                j--;
            } else {
                break;
            }
        }

        return highestScore;
    }
};