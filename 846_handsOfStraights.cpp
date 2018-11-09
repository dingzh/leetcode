class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int size = hand.size();
        
        set<int> hand_types;
        unordered_map<int, int> hand_cnts;
        
        for (int h : hand) {
            if (++hand_cnts[h] == 1) 
                hand_types.insert(h);
        }

        while (hand_types.size()) {
            int min_hand = *hand_types.begin();
            int hand_num = hand_cnts[min_hand];
            for (int i = 0; i < W; ++i) {
                int this_num = hand_cnts[min_hand + i];
                if (this_num < hand_num) {
                    return false;
                } else if (this_num == hand_num) {
                    hand_cnts.erase(min_hand+i);
                    hand_types.erase(min_hand+i);
                } else  {
                    hand_cnts[min_hand + i] -= hand_num;
                }
            }
        }

        return true;
    }
};
