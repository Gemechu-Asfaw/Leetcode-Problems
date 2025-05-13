class Solution {
public:
    bool isPathCrossing(string path) {
        
        unordered_map<int, unordered_map<int, bool>> crossedPoints;
        int x = 0, y = 0;
        int n = path.length();

        // Pointing the first coordinate (0, 0) as true
        crossedPoints[0][0] = true;

        for (int i=0; i<n; i++){

            // Changing x and y coordinate with respect to the directions given
            if (path[i]=='N'){
                y--;
            } else if (path[i]=='S'){
                y++;
            } else if (path[i]=='W'){
                x--;
            } else {
                x++;
            }

            // Checking if given path is crossed or not
            if (crossedPoints.find(x)!=crossedPoints.end() && crossedPoints[x].find(y)!=crossedPoints[x].end()){
                return true;
            }

            // Storing the new position in the map
            crossedPoints[x][y] = true;
        }

        return false;
    }
};