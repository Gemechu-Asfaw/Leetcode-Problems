class Point{
public:
    int index, value1, value2;

    Point(int index, int value1, int value2){
        this->index = index;
        this->value1 = value1;
        this->value2 = value2;
    }
};

class Solution {
public:
    static bool cmp(Point* &x, Point* &y){
        return x->value1 < y->value1;
    }

    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();
        int addIndex = 0;
        long long sum = 0;
        vector<Point*> points;
        vector<long long> ans(n, 0);
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i=0; i<n; i++){
            points.push_back(new Point(i, nums1[i], nums2[i]));
        }

        sort(points.begin(), points.end(), cmp);

        for (int i=0; i<n; i++){

            if (points[i]->value1 != points[addIndex]->value1) {
                for (int j=addIndex; j<i; j++){
                    Point* current = points[j];
                    if (j < k){
                        pq.push(current->value2);
                        sum = sum + (long long)current->value2;
                    } else {
                        int top = pq.top();
                        if (top < current->value2){
                            pq.pop();
                            pq.push(current->value2);
                            sum = sum - (long long)top + (long long)current->value2;
                        }
                    }
                }
                addIndex = i;
            }

            ans[points[i]->index] = sum;
        }

        return ans;
    }
};