class Solution {
public:
    bool isPathCrossing(string path) {
        // set<pair<int, int>> coords;
        // pair<int, int> coord = {0, 0};
        // for(char c : path){
        //     coords.insert(coord);
        //     if(c=='N') coord.second++;
        //     if(c=='S') coord.second--;
        //     if(c=='W') coord.first--;
        //     if(c=='E') coord.first++;

        //     if(coords.find(coord)!=coords.end()){
        //         return true;
        //     }
        // }
        // return false;

        unordered_set<string> coords;
        coords.insert("0,0");
        pair<int, int> coord = {0, 0};
        for(char c : path){
            if(c=='N') coord.second++;
            if(c=='S') coord.second--;
            if(c=='W') coord.first--;
            if(c=='E') coord.first++;
            string coordString = to_string(coord.first)+','+to_string(coord.second);
            cout<<coordString<<endl;

            if(coords.find(coordString)!=coords.end()){
                return true;
            }
            
            coords.insert(coordString);
        }
        return false;
    }
};