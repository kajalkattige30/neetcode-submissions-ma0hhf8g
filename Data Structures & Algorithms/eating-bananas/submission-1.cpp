class Solution {
public:
    int findMin(vector<int> &arr) {
        int mn = INT_MAX;
        for(int i = 0; i < arr.size(); i++) {
            mn = min(mn, arr[i]);
        }
        return mn;
    }

    int findMax(vector<int> &arr) {
        int mx = INT_MIN;
        for(int i = 0; i < arr.size(); i++) {
            mx = max(mx, arr[i]);
        }
        return mx;
    }

    int calculateHours(vector<int> &piles, int speed) {
        int sum = 0;
        for(int i = 0; i < piles.size(); i++) {
            sum += ceil(double(piles[i])/speed);
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = findMax(piles);
        int ans;

        while(start <= end) {
            int mid = start + (end - start)/2;
            int hours = calculateHours(piles, mid);
            if(hours > h) {
                start = mid+1;
            }
            else {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }
};
