class MedianFinder {
    double median;
    priority_queue<int> ldata;
    priority_queue<int, vector<int>, greater<int>> rdata;
public:
    /** initialize your data structure here. */
    MedianFinder(): median(0.0) {}
    
    void addNum(int num) {
        int lsize = ldata.size(), rsize = rdata.size();
        if (lsize == rsize) {
            if (median < num) {
                rdata.push(num);
                median = rdata.top();
            } else {
                ldata.push(num);
                median = ldata.top();
            }
        } else if (lsize < rsize) {
            if (median < num) {
                ldata.push(median);
                rdata.pop();
                rdata.push(num);
                median = (median + rdata.top()) / 2.0;
            } else {
                ldata.push(num);
                median = (median + ldata.top()) / 2.0;
            }
        } else { // lsize > rsize
            if (median <= num) {
                rdata.push(num);
                median = (median + rdata.top()) / 2.0;
            } else {
                rdata.push(median);
                ldata.pop();
                ldata.push(num);
                median = (median + ldata.top()) / 2.0;
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
