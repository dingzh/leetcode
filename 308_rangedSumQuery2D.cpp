class BinIndexedTree {
    int* arr;
    int size;
public:
    BinIndexedTree(vector<int>& nums) {
        size = nums.size();
        arr = new int[size+1]; //1-indexed array
        for (int i = 0; i <= size; ++i) {
            arr[i] = 0;
        }
        for (int i = 0; i < size; ++i) {
            update(i, nums[i]);
        }
    }
    
    ~BinIndexedTree() {
        delete [] arr;
    }

    void update(int idx, int delta) {
        ++idx; // convert idx to be 1-indexed
        while (idx <= size) {
            arr[idx] += delta;
            idx += idx & (-idx);
        }
    }

    // return sum of nums[0, idx] inclusive
    int getSum(int idx) {
        ++idx;
        int ret = 0;
        while (idx) {
            ret += arr[idx];
            idx -= idx & (-idx);
        }
        return ret;
    }
};

class NumMatrix {
    BinIndexedTree** bits;
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>&& matrix):matrix(matrix) {
        int r = matrix.size();
        bits = new BinIndexedTree*[r];
        for (int i = 0; i < r; ++i) {
            bits[i] = new BinIndexedTree(matrix[i]);
        }
    }

    void update(int row, int col, int val) {
        cout << row << endl << col << endl;
        int delta = val - matrix[row][col];
        matrix[row][col] = val;
        bits[row]->update(col, delta);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;
        for (int r = row1; r <= row2; ++r)
            ret += bits[r]->getSum(col2) - bits[r]->getSum(col1-1);
        return ret;
    }
    
    ~NumMatrix() {
        for (int i = 0; i < matrix.size(); ++i) {
            delete bits[i];
        }
        delete [] bits;
    }
    
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
