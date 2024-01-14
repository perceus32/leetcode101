class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1!=n2){return false;}

        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        vector<int> freqCount1;
        vector<int> freqCount2;
        // vector<char> freqCount3;
        // vector<char> freqCount4;

        set<char> charCount1;
        set<char> charCount2;
        for(auto c: word1){
            freq1[c]++;
            charCount1.insert(c);
        }
        for(auto c: word2){
            freq2[c]++;
            charCount2.insert(c);
        }
        if(charCount1!=charCount2){
            // cout<<"hello";
            return false;
        }

        for(auto i: freq1){
            freqCount1.push_back(i.second);
            // freqCount3.push_back(i.first);
            // freqCounta.insert(i);
        }
        sort(freqCount1.begin(), freqCount1.end());
        // sort(freqCount3.begin(), freqCount3.end());




        for(auto i: freq2){
            freqCount2.push_back(i.second);
            // freqCount4.push_back(i.first);
            // freqCounta.insert(i);
        }
        sort(freqCount2.begin(), freqCount2.end());
        // sort(freqCount4.begin(), freqCount4.end());




        if(freqCount1==freqCount2){
            return true;
        }
        return false;
    }
};