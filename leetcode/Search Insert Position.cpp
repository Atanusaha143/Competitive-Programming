class Solution {
public:
    int searchInsert(vector<int>& vec, int t)
    {
        long long l = 0, r = vec.size()-1, dist = INT_MAX, idx = 0;
        while(l<=r)
        {
            int mid =  l + (r - l) / 2;
            if(vec[mid] == t) return mid;
            else if(vec[mid] > t)
            {
                if(vec[mid] - t < dist)
                {
                    dist = vec[mid] - t;
                    idx = mid;
                }
                r = mid - 1;
            }
            else
            {
                if(t - vec[mid] < dist)
                {
                    dist = t - vec[mid];
                    idx = mid;
                }
                l = mid + 1;
            }
        }
        if(vec[idx] < t) idx++;
        return idx;
    }
};
