class MovingAverage {
    int sum;
    int size;
    queue<int> window;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size):size(size), sum(0) {

    }

    double next(int val) {
        int curr_size = window.size();
        if (curr_size < size) {
            sum += val;
            window.push(val);
            return (double) sum / (curr_size + 1);
        } else {
            sum -= window.front();
            window.pop();
            sum += val;
            window.push(val);
            return (double) sum / curr_size;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
