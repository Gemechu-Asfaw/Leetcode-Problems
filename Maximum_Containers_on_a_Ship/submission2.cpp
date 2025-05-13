class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int containerWeight = n*n*w;
        if (containerWeight <= maxWeight){
            return n*n;
        } else {
            return (maxWeight/w);
        }
    }
};