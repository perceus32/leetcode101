class Solution {
    //TC: O(N) \
    or O(NlogN) in the second approach
public:
    // void swapFn(vector<int> &arr, int i, int j){
    //     while(i<j){
    //         int temp = arr[j];
    //         arr[j] = arr[i];
    //         arr[i] = temp;
    //         i++;
    //         j--;
    //     }
    // }
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        unordered_map<int, int> hash;
        for(int i = 0; i<n; i++){
            hash[target[i]]++;
        }
        for(int i = 0; i<n; i++){
            hash[arr[i]]--;
            if(hash[arr[i]]<0){
                return false;
            }
        }
        return true;


        //APPROACH 2
        // sort(begin(target), end(target));
        // sort(begin(arr), end(arr));
        // return target==arr;
    }
};