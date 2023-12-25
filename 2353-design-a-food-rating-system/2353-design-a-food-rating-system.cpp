class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> cuisines_map;
    unordered_map<string, string> food_cuisines;
    unordered_map<string, int> food_rating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++){
            cuisines_map[cuisines[i]].insert(make_pair( -ratings[i], foods[i]));
            food_cuisines[foods[i]]=cuisines[i];
            food_rating[foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisines[food];
        cuisines_map[cuisine].erase({ -food_rating[food], food});
        cuisines_map[cuisine].insert({ -newRating, food});
        food_rating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisines_map[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */