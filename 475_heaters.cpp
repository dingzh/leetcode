class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(begin(heaters), end(heaters));
        const int max_int = numeric_limits<int>::max();
        
        int min_radius = 0;
        for (int house : houses) {
            int radius = max_int;
            auto p = upper_bound(begin(heaters), end(heaters), house);
            if (p != heaters.end()) {
                radius = *p - house;
            }
            
            if (p != heaters.begin()) {
                radius = min(radius, house - *(prev(p)));
            }
            
            min_radius = max(min_radius, radius);
        } 
        return min_radius;
    }
};
