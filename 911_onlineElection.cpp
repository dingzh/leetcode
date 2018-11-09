class TopVotedCandidate {
    vector<pair<int,int>> winner_at_time; // pair (time, person)
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        if (persons.size() == 0) return ;
        unordered_map<int, int> vote_count;
        
        // count first one
        winner_at_time.emplace_back( times[0], persons[0] );
        vote_count[ persons[0] ] = 1;
        int max_vote = 1;
        // count the rest
        for ( int i = 1; i < persons.size(); ++i ) {
            int person = persons[i];
            int this_vote_count = ++vote_count[person];
            if (this_vote_count >= max_vote) {
                if (winner_at_time.back().second != person)
                    winner_at_time.emplace_back(times[i], person);
                max_vote = this_vote_count;
            }
        }
    }

    int q(int t) {
        auto past_winner = upper_bound(
                begin(winner_at_time), end(winner_at_time),
                make_pair(t, 0), 
                [](auto& lhs, auto& rhs) -> bool{
                    return lhs.first < rhs.first;
                });
        int ret = prev(past_winner)->second;
        return ret;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
