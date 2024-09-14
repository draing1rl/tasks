#include <iostream>
#include <vector>


std::vector<int> sort(std::vector<int> foo, int l, int r) {
    if ((l+1) == r) {
        std::vector<int> rt {foo[l]};
        return rt;
    }

    int mid = (l + r + 1) / 2;

    std::vector<int> arr1 = sort(foo, l, mid);
    std::vector<int> arr2 = sort(foo, mid, r);
    std::vector<int> ret;

    int it1 {0};
    int it2 {0};
    int it3 {};
    while (it3 < r) {
        int nFromFirst = arr1[it1];
        int nFromSecond = arr2[it2];
        if (nFromFirst > nFromSecond) {
            ret.push_back(nFromSecond);
            it2++;
        } else {
            ret.push_back(nFromFirst);
            it1++;
        }

        if (it1 >= arr1.size()) {
            for (int i = it2; i < arr2.size(); i++) {
                ret.push_back(arr2[i]);
            }
            break;
        }
        if (it2 >= arr2.size()) {
            for (int i = it1; i < arr1.size(); i++) {
                ret.push_back(arr1[i]);
            }
            break;
        }

        it3++;
    }

    return ret;

}

int * sortWtVector(int * arr, int l, int r) {

    if ((l+1) == r) {
        int * rt = new int[1];
        rt[0] = arr[l];
        return rt;
    }

    int mid = (l + r) / 2;

    int * arr1 = sortWtVector(arr, l, mid);
    int * arr2 = sortWtVector(arr, mid, r);
    int * ret = new int[r];

    int it1 {};
    int it2 {};
    int it3 {};
    while (it3 < r) {
        int nFirst = arr1[it1];
        int nSecond = arr2[it2];

        if (nFirst > nSecond) {
            ret[it3] = nSecond;
            it2++;
        } else {
            ret[it3] = nFirst;
            it1++;
        }

        it3++;

        if (it1 >= (mid - l)) {
            for (int i = it2; it3 < r; i++) {
                ret[it3] = arr2[i];
                it3++;
            }
            break;
        } else if (it2 >= (r - mid)) {
            break;
        }
    }

    delete [] arr1;
    delete [] arr2;

    return ret;
}

int main() {
    std::vector<int> foo = {32, 1, 346, 67, 2, 967, 23, 5555, 766, 10};
    int foo2 [] {32, 1, 346, 67, 2, 967, 23, 5555, 766, 10};
    
    std::vector<int> res {sort(foo, 0, foo.size())};
    int * res2 = sortWtVector(foo2, 0, 10);
    for (int i = 0; i < 10; i++) {
        std::cout << res[i] << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < 10; i++) {
        std::cout << res2[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
