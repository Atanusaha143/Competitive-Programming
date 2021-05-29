class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int len = deck.size();
        map <int,int> mp;
        for(int i=0; i<len; i++) mp[deck[i]]++;
        int mini = INT_MAX;
        for(auto x : mp) mini = min(mini,x.second);
        if(mini < 2) return false;
        bool ans = false;
        for(int i=2; i<=mini; i++)
        {
            int count = 0;
            for(auto x : mp)
            {
                if(x.second%i) break;
                else count++;
            }
            if(count == mp.size()) ans = true;
        }
        return ans;
    }
};
