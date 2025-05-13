class Person{
    public:
    string name;
    int height;

    Person(string name, int height){
        this->name = name;
        this->height = height;
    }
};

class Solution {
public:
    static bool cmp(Person *a, Person *b){
        return a->height > b->height;
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector<string> ans;
        vector<Person*> persons;
        int n = names.size();

        for (int i=0; i<n; i++){
            persons.push_back(new Person(names[i], heights[i]));
        }

        sort(persons.begin(), persons.end(), cmp);

        for (int i=0; i<n; i++){
            ans.push_back(persons[i]->name);
        }

        return ans;
    }
};