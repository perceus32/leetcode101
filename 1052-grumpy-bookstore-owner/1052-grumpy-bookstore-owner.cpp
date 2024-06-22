class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sat = 0;
        for(int i=0; i<n; i++){
            sat += customers[i]*(1-grumpy[i]);
            // unsat += customers[i]*grumpy[i];
        }
        int maxUnsat = 0;
        for(int i=0; i<n-minutes+1; i++){
            // cout<<i<<endl;
            int track = 0;
            for(int j=0; j<minutes; j++){
                track += grumpy[i+j]*customers[i+j];
            }
            maxUnsat = max(maxUnsat, track);
        }
        return sat + maxUnsat;
    }
};