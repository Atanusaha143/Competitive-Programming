class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        int len = arr.size();
        int prefix[len];
        prefix[0] = arr[0];
        for(int i=1; i<len; i++)
            prefix[i] = prefix[i-1] ^ arr[i];

        vector <int> ans;
        for(int i=0; i<queries.size(); i++)
        {
            int L = queries[i][0];
            int R = queries[i][1];

            if(L == 0) ans.push_back(prefix[R]);
            else ans.push_back(prefix[L-1]^prefix[R]);
        }
        return ans;
    }
};
