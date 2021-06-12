class Solution
{
public:
    vector<int> twoSum(vector<int>& vec, int t)
    {
        vector <int> twoSum;
        for(int i=0; i<vec.size(); i++)
        {
            int need = t - vec[i];
            int l = 0, r = vec.size()-1, ans = -1;
            while(l<=r)
            {
                int mid =  l + (r - l) / 2;
                if(vec[mid] == need and mid != i) {ans = mid; break; }
                if(vec[mid] < need) l = mid + 1;
                else r = mid - 1;
            }
            if(ans != -1)
            {
                twoSum.push_back(i+1);
                twoSum.push_back(ans+1);
                sort(twoSum.begin(),twoSum.end());
                break;
            }
        }
        return twoSum;
    }
};
