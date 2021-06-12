class Solution {
public:
    vector<int> intersection(vector<int>& vec1, vector<int>& vec2) {
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        set <int> ans;
        if(vec1.size() < vec2.size())
        {
            for(int i=0; i<vec1.size(); i++)
            {
                int curr = vec1[i];
                int l = 0, r = vec2.size()-1;
                while(l<=r)
                {
                    int mid =  l + (r - l) / 2;
                    if(vec2[mid] == curr) { ans.insert(curr); break; }
                    if(vec2[mid] > curr) r = mid - 1;
                    else l = mid + 1;
                }
            }
        }
        else
        {
            for(int i=0; i<vec2.size(); i++)
            {
                int curr = vec2[i];
                int l = 0, r = vec1.size()-1;
                while(l<=r)
                {
                    int mid =  l + (r - l) / 2;
                    if(vec1[mid] == curr) { ans.insert(curr); break; }
                    if(vec1[mid] < curr) l = mid + 1;
                    else r = mid - 1;
                }
            }
        }

        vector<int> intersection;
        for(auto x : ans) intersection.push_back(x);
        return intersection;
    }
};
