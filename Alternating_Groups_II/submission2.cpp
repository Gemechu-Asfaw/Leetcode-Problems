class Solution {
public:

    // this function was used to print the current window (for debugging purpose)
    void printWindow(deque<pair<int,int>> window, int k, int conflicts){

        for (int i=0; i<k; i++){
            pair<int,int> front = window.front();
            window.pop_front();
            cout << front.first << "-->" << front.second << "   ";
        }
        cout << conflicts <<  endl;
    }

    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
        // Initialization of window and other variables
        int ptr = 0, conflicts = 0, ans = 0, n = colors.size(), status;
        
        // window[i]->first = color, window[i]->second = 1 (if it has same color to it's right neighbour)
        deque<pair<int,int>> window;
        for (int i=0; i<=k-1; i++){
            // logic to check if next step has same color as current one and if it is last step of window than there is no current conflict
            if (colors[(i+1)%n]==colors[i] && i!=k-1){
                status = 1;
                conflicts++;
            } else {
                status = 0;
            }
            window.push_back({colors[i],status});
        }
        
        while (ptr<n){
            
            // adding 1 to the answer if there is conflict
            if (!conflicts) ans++;
            
            // modifying the window
            ptr++;
            if (ptr < n){
                pair<int, int> front = window.front();
                pair<int,int> back = window.back();
                pair<int,int> newEntry = {colors[(ptr+k-1)%n], 0};
                window.pop_front();
                if (front.second == 1) conflicts--;
                if (back.first == newEntry.first){
                    window.back().second = 1;
                    conflicts++;
                }
                window.push_back(newEntry);
            }
        }
        
        return ans;
    }
};