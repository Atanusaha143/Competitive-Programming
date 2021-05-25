class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set <int> st;
    int len = nums.size();
    for(int i=0; i<len; i++) st.insert(nums[i]);
    if(st.size() < 3)
    {
        vector <int> ans;
        for(auto x : st) ans.push_back(x);
        sort(ans.begin(), ans.end(), greater<int>());
        return ans[0];
    }
    else
    {
        vector <int> ans;
        for(auto x : st) ans.push_back(x);
        sort(ans.begin(), ans.end(), greater<int>());
        return ans[2];
    }
    }
};
