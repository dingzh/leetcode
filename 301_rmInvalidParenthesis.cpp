class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int open_to_remove = 0;
        int close_to_remove = 0;
        for (char ch : s) {
            switch (ch) {
                case '(':
                    ++open_to_remove;
                    break;
                case ')':
                    if (open_to_remove) { --open_to_remove; }
                    else { ++close_to_remove; }
            }
        }
        
        string str_builder;
        unordered_set<string> result_set;
        removeInvalidPAux(0, 0, open_to_remove, close_to_remove, s, str_builder, result_set);
        
        vector<string> ret( make_move_iterator(begin(result_set)),
                            make_move_iterator(end(result_set)) );
        return ret;
    }
    
    void removeInvalidPAux(int curr, int oc, int otr, int ctr, string& s, 
            string& result, unordered_set<string>& result_set) {

        if (otr + ctr > s.size() - curr) {return ;}
        if (curr == s.size()) {
            result_set.insert(result);
            return ;
        }
        
        int this_char = s[curr];
        switch (this_char) {
            case '(':
                if (otr) 
                    removeInvalidPAux(curr+1, oc, otr-1, ctr, s, result, result_set);

                result.push_back(this_char);
                removeInvalidPAux(curr+1, oc+1, otr, ctr, s, result, result_set);
                result.pop_back();
                break;
            case ')':
                if (ctr) 
                    removeInvalidPAux(curr+1, oc, otr, ctr-1, s, result, result_set);
                
                if (oc) { // not removing this one
                    result.push_back(this_char);
                    removeInvalidPAux(curr+1, oc-1, otr, ctr, s, result, result_set);
                    result.pop_back();
                }
                break;
            default:
                result.push_back(this_char);
                removeInvalidPAux(curr+1, oc, otr, ctr, s, result, result_set);
                result.pop_back();
        }
    }
};
