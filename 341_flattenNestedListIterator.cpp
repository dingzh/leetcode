/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    queue<int> q;

    void helper(NestedInteger& ni) {
        if (ni.isInteger()) {
            q.push(ni.getInteger());
            return;
        }
        auto nestedList = ni.getList();
        for (auto& x : nestedList) {
            helper(x);
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto x : nestedList) helper(x);
    }


    int next() {
        int ret = q.front();
        q.pop();

        return ret;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
