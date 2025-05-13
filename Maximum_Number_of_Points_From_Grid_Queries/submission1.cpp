class Point{
public:
    int value;
    int x;
    int y;

    Point(int value, int x, int y){
        this->value = value;
        this->x = x;
        this->y = y;
    }
};

class cmp{
public:
    bool operator()(Point* &a, Point* &b){
        return a->value > b->value;
    }
};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        
        int m = grid.size(), n = grid[0].size(), q = queries.size();
        vector<pair<int, int>> updatedQueries(q);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> ans(q, 0);
        priority_queue<Point*, vector<Point*>, cmp> pq;
        int count = 0;

        for (int i=0; i<q; i++){
            updatedQueries[i] = {queries[i], i};
        }

        sort(updatedQueries.begin(), updatedQueries.end());

        pq.push(new Point(grid[0][0], 0, 0));
        visited[0][0] = true;

        for (int i=0; i<q; i++){
            int value = updatedQueries[i].first, index = updatedQueries[i].second;

            while (!pq.empty()){
                Point* top = pq.top();
                int topValue = top->value, x = top->x, y = top->y;

                if (value <= topValue) break;

                pq.pop();
                count++;
                vector<pair<int, int>> neighbours = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};

                for (auto neighbour : neighbours){
                    if (neighbour.first>=0 && neighbour.second>=0 && neighbour.first<m && neighbour.second<n && !visited[neighbour.first][neighbour.second]){
                        pq.push(new Point(grid[neighbour.first][neighbour.second], neighbour.first, neighbour.second));
                        visited[neighbour.first][neighbour.second] = true;
                    }
                }
            }
            
            ans[index] = count;
        }

        return ans;
    }
};