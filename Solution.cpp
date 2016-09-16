//
// Created by liujing on 9/16/16.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void test_vector() {
        vector<int> a{0, 1, 2};
        for (int i = 0; i < 3; i++) {
            cout << a[i] << endl;
        }
    }

    /**
     * 2.1.1
     */
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) return 0;
        int index = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return index + 1;
    }


    /**
     * 2.1.5
     */
    double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
        const int m = A.size();
        const int n = B.size();
        int total = m + n;
        if (total & 0x1)
            return find_kth(A.begin(), m, B.begin(), n, total / 2 + 1);
        else
            return (find_kth(A.begin(), m, B.begin(), n, total / 2)
                    + find_kth(A.begin(), m, B.begin(), n, total / 2 + 1)) / 2.0;
    }

private:
    static int find_kth(vector<int>::const_iterator A, int m, vector<int>::const_iterator B, int n, int k) {
        //always assume that m is equal or smaller than n
        if (m > n) return find_kth(B, n, A, m, k);
        if (m == 0) return *(B + k - 1);
        if (k == 1) return min(*A, *B);
        //divide k into two parts
        int ia = min(k / 2, m), ib = k - ia;
        if (*(A + ia - 1) < *(B + ib - 1))
            return find_kth(A + ia, m - ia, B, n, k - ia);
        else if (*(A + ia - 1) > *(B + ib - 1))
            return find_kth(A, m, B + ib, n - ib, k - ib);
        else
            return A[ia - 1];
    }

};

int main() {
    Solution M;        //用定义好的类创建一个对象 点M

    /**
     * 2.1.1
     */
//    vector<int> vec {1, 1, 2, 3, 4, 1, 2, 3, 4};
//    cout << M.removeDuplicates(vec) << endl;


    /**
     * 2.1.5
     */
    vector<int> vec1 {33,55,88};
    vector<int> vec2 {44,54,70,80,90};

    cout << M.findMedianSortedArrays(vec1,vec2) << endl;

    return 0;
}
