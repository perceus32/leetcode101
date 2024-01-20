class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        int i=0, j=0;
        string res;
        while(i<n1 && j<n2){
            res+=word1[i];
            res+=word2[j];
            i++;
            j++;
        }
        if(i!=n1){res.append(word1.substr(i, n1-i));}
        if(j!=n2){res.append(word2.substr(j, n2-i));}

        return res;
    }
};