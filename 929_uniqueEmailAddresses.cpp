class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        string canonical_email;
        unordered_set<string> canonical_emails;
        
        for (string& email : emails) {
            canonical_email.clear();
            int i = 0, len = email.length();
            while (i < len && email[i] != '+' && email[i] != '@') {
                if (email[i] != '.') 
                    canonical_email.push_back(email[i]);
                ++i;
            }
            while (i < len && email[i] != '@') ++i;
            while (i < len) canonical_email.push_back(email[i++]);
            canonical_emails.emplace( move(canonical_email) );
        }
        
        return canonical_emails.size();
    }
};
