class TopVotedCandidate {
    unordered_map<int, vector<int>> votes;
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        for ( int i = 0; i < persons.size(); ++i ) {
            votes[ persons[i] ].push_back( times[i] );
            // each vector will be strictly increasing too
        }
    }
    
    int q(int t) {
        int max_vote_time = numeric_limits<int>::max();
        int person, max_vote_cnt = 0;

        for (auto& person_votes : votes) {
            vector<int>& vote_rec = person_votes.second;
            auto past_last_vote = upper_bound( begin(vote_rec), end(vote_rec), t );
            int vote_cnt = distance(vote_rec.begin(), past_last_vote);
            if (vote_cnt == 0) continue; // check before we access last vote
            int vote_time = *prev(past_last_vote);
            if (vote_cnt > max_vote_cnt ||
                    vote_cnt == max_vote_cnt && vote_time > max_vote_time) {
                max_vote_time = vote_time;
                max_vote_cnt = vote_cnt;
                person = person_votes.first;
            }
        }
        return person;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
