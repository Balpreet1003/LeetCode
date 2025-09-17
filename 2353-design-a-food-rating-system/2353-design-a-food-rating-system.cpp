class FoodRatings {
    struct cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if(a.first == b.first) return a.second > b.second; 
            return a.first < b.first;
        }
    };
    
    unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, cmp>> m1; 
    unordered_map<string, int> m2; 
    unordered_map<string, string> foodToCuisine; 

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0; i<n; i++){
            m1[cuisines[i]].push({ratings[i], foods[i]});
            m2[foods[i]] = ratings[i];
            foodToCuisine[foods[i]] = cuisines[i];
        }
    }

    void changeRating(string food, int newRating) {
        m2[food] = newRating;
        m1[foodToCuisine[food]].push({newRating, food});
    }

    string highestRated(string cuisine) {
        auto &pq = m1[cuisine];
        while(m2[pq.top().second] != pq.top().first) { 
            pq.pop();
        }
        return pq.top().second;
    }
};


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */