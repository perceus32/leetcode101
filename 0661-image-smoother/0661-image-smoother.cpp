class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        //TC : O(M*N)  ; SC: O(1)
        //m = number of rows; n = number of columns
        int m = img.size(), n = img[0].size(), sum = 0, count = 0;
        //vector<vector<int>> res(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                //narrowed down to a cell
                for(int k = -1; k<2; k++){
                    for(int l=-1; l<2; l++){
                        //cout<<i<<" "<<j<<" "<<i+k<<" "<<j+l<<endl;
                        if((i+k)>=0 && (i+k)<m && (j+l)>=0 && (j+l)<n){
                            sum += (img[i+k][j+l] & 0xFF);
                            count++;
                        }
                    }
                }
                img[i][j] |= (sum/count << 8);
                sum = 0;
                count = 0;
            }
        }
        for(int i=0 ;i<m; i++){
            for(int j=0; j<n; j++){
                img[i][j] >>= 8;
            }
        }
        return img;
    }
};