class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        int i =0, j=0;
        while(i<n1 && j<n2){
            char c1 = s[i];
            char c2 = t[j];
            if(c1==c2){
                i++;
                j++;
            }else{
                j++;
            }
        }
        if(i==n1){return true;}
        return false;


        //PSEUDO code for follow up - 
        /*
        vector<vector<int>> v(26, v(t.size, -1))
        start with end of t -> start filling v
        if letter not found -> -1
        if found -> 0
        further if not found -> last index found

        for each s -> iterate through its letters -> find them in t matrix O(n) time where n is size of s
        */
    }
};