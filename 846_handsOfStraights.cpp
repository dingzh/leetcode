class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int size = hand.size();
        
        priority_queue<int, vector<int>, greater<int>> hand_types;  // for ordering
        unordered_map<int, int> hand_cnts;
        
        for (int h : hand) {
            if (++hand_cnts[h] == 1) 
                hand_types.push(h);
        }

        while (!hand_types.empty()) {
            int min_hand = hand_types.top();
            hand_types.pop();
            
            int hand_num = hand_cnts[min_hand];
            if (!hand_num) continue ;
            for (int i = 0; i < W; ++i) {
                int& this_num = hand_cnts[min_hand + i];
                this_num -= hand_num;
                if (this_num < 0) return false;
            }
        }

        return true;
    }
};
