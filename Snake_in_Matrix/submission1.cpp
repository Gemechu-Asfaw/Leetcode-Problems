class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        pair<int, int> position = {0,0};
        for (string command : commands){
            if (command == "UP") position.first = position.first - 1;
            else if (command == "DOWN") position.first = position.first + 1;
            else if (command == "LEFT") position.second = position.second - 1;
            else position.second = position.second + 1;
        }
        return n*position.first + position.second;
    }
};