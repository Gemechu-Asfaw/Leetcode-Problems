class NumberContainers {
public:

    unordered_map<int, int> indexToNumber;
    unordered_map<int, set<int>> numberToIndex;

    NumberContainers() {

    }
    
    void change(int index, int number) {
        if (this->indexToNumber.find(index) != this->indexToNumber.end()){
            int oldNumber = this->indexToNumber[index];
            this->numberToIndex[oldNumber].erase(index);
        }

        this->indexToNumber[index] = number;
        this->numberToIndex[number].insert(index);
    }
    
    int find(int number) {
        return (!this->numberToIndex[number].empty()) ? *(this->numberToIndex[number].begin()) : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */