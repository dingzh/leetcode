class Solution {
    unordered_map<string,string> record;
    static constexpr char charset[] =
        "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    const int key_len = 7;
    uniform_int_distribution<> dis{0, 61};
    default_random_engine gen{ random_device()() };
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = getRandKey();
        while (record.count(key)) key = getRandKey();

        record[key] = longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (record.count(shortUrl)) return record[shortUrl];
        return {};
    }

    string getRandKey() {
        string ret;
        for (int i = 0; i < key_len; ++i)
            ret.push_back(charset[dis(gen)]);

        return ret;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
