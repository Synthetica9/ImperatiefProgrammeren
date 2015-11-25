#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>

/* Assignment 2.1
 * a. This is O(1), because all that happens is a constant amount of integer arithmatic.
 * b. This is O(√N), because there is a for loop that does a constant amount of work, that runs √N times
 * c. This is O(1), because it is a simiple lookup of a stored value
 * d. This is O(K√N), because there is a loop that runs K times (length of the vector) with a runtime of √N (size of
 *    the individual elements)
 * e. This is O(N), because there is a loop that runs once for every element of N
 */


/* Assignment 2.2 a:
 * Initial state:
 * {3, 28, 14, -5, 6, 12, 3}
 *
 * {28, 14, -5, 6, 12, 3}
 * 3
 *
 * {14, -5, 6, 12, 3}
 * 3
 * └─ 28
 *
 * {14, -5, 6, 12, 3}
 * 28
 * └─ 3
 *
 * {-5, 6, 12, 3}
 * 28
 * ├─ 3
 * └─ 14
 *
 * {6, 12, 3}
 * 28
 * ├─ 3
 * |  └─ -5
 * └─ 14
 *
 * {12, 3}
 * 28
 * ├─ 3
 * |  ├─ -5
 * |  └─ 6
 * └─ 14
 *
 * ∅
 * 28
 * ├─ 6
 * |  ├─ -5
 * |  └─ 3
 * └─ 14
 *    ├─ 12
 *    └─ 3
 *
 * ∅
 * 3
 * ├─ 6
 * |  ├─ -5
 * |  └─ 3
 * └─ 14
 *    ├─ 12
 *    └─ 28
 *
 * {28}
 * 14
 * ├─ 6
 * |  ├─ -5
 * |  └─ 3
 * └─ 3
 *    └─ 12
 *
 * {28}
 * 14
 * ├─ 6
 * |  ├─ -5
 * |  └─ 3
 * └─ 12
 *    └─ 3
 *
 * {28}
 * 3
 * ├─ 6
 * |  ├─ -5
 * |  └─ 3
 * └─ 12
 *    └─ 14
 *
 * {14, 28}
 * 3
 * ├─ 6
 * |  ├─ -5
 * |  └─ 3
 * └─ 12
 *
 * {14, 28}
 * 12
 * ├─ 6
 * |  ├─ -5
 * |  └─ 3
 * └─ 3
 *
 * {14, 28}
 * 3
 * ├─ 6
 * |  ├─ -5
 * |  └─ 12
 * └─ 3
 *
 * {12, 14, 28}
 * 3
 * ├─ 6
 * |  └─ -5
 * └─ 3
 *
 * {12, 14, 28}
 * 6
 * ├─ 3
 * |  └─ -5
 * └─ 3
 *
 * {12, 14, 28}
 * -5
 * ├─ 3
 * |  └─ 6
 * └─ 3
 *
 * {6, 12, 14, 28}
 * -5
 * ├─ 3
 * └─ 3
 *
 * {6, 12, 14, 28}
 * 3
 * ├─ -5
 * └─ 3
 *
 * {3, 6, 12, 14, 28}
 * 3
 * └─ -5
 *
 * {3, 6, 12, 14, 28}
 * 3
 * └─ -5
 *
 * {3, 6, 12, 14, 28}
 * -5
 * └─ 3
 *
 * {3, 3, 6, 12, 14, 28}
 * -5
 *
 * {-5, 3, 3, 6, 12, 14, 28}
 *
 * (Yes, this was all done by hand)
 *
 * b:
 * push_up: there are log(N) "layers". An item has to traverse (at most) all those layers, so it is O(log(N))
 * build_heap: calls push_up on all N elements, so it has to do O(N * log(N)) operations
 * push_down: is basically the same as push_up, and also has to traverse at most one path; so this is also O(log(N))
 * pick_heap is basically the same as build_heap, except shrinking the heap instead of growing it. So, this is also
 * O(N * log(N))
 *
 * Since heapsort as a whole is just all these steps one after another, once, it is as a whole the complexity of the
 * most complex step, O(N log(N)).
 */

using namespace std;

int size(vector<char> &r) {// pre-condition:
    assert (true);
//  post-condition: result is the number of elements in r
    return static_cast<int>(r.size());
}

int add_without_dup(char x, vector<char> &r) {// pre-condition:
    assert (true);
//  post-condition: x is added to the end of r if it is not yet present in r
//                  the result is the number of comparisons performed in this function
    int i = 0;
    while (i < size(r) && r[i] != x)
        i++;
    if (i == size(r))
        r.push_back(x);
    return i;
}

/* This is O(n^2), because for every element in the array, every previous element has to be checked to make sure it
 * hasn't been added to the vector yet.*/

int remove_dup(vector<char> &source, vector<char> &dest) {// pre-condition:
    assert (size(dest) == 0);
//  post-condition: dest is a copy of source without duplicate elements
//                  the result is the number of comparisons performed in this function
    int nr_of_comparisons = 0;
    for (int i = 0; i < size(source); i++)
        nr_of_comparisons += add_without_dup(source[i], dest);
    return nr_of_comparisons;
}


bool is_sorted(vector<char> &source) {
    // Pre-condition:
    assert(true);
    // Post-conditions:
    // Returns true if source is sorted, false otherwise
    bool sorted = true;
    char olditem = 0;
    for (char item : source) {
        sorted = (olditem <= item) && sorted;
        olditem = item;
    }
    return sorted;
}

int remove_sort_dup(vector<char> &source, vector<char> &dest) {
// pre-condition:
    assert (size(dest) == 0 && is_sorted(source));
// post-condition: dest is a copy of source without duplicate elements
// result is the number of comparisons performed in this function
    char prev_char = '\0';

    for (char curr_char : source) {
        if (prev_char != curr_char) {
            dest.push_back(curr_char);
            prev_char = curr_char;
        }
    }
}

void fill(string txt, vector<char> &r) {
// pre-condition:
    assert (size(r) == 0);
//  post-condition: r contains all characters of txt
    for (int i = 0; i < txt.size(); i++)
        r.push_back(txt[i]);
}

void show(vector<char> &r) {
// pre-condition:
    assert (true);
//  post-condition: all elements of r are displayed (from index 0 to index size(r)-1)
    for (int i = 0; i < size(r); i++)
        cout << r[i];
}

int main() {
    vector<char> source;
    fill("Alice was beginning to get very tired of sitting by her sister on the bank", source);
    vector<char> dest;
    int nr_of_comparisons = remove_dup(source, dest);
    cout << "The source is: " << endl;
    show(source);
    cout << endl << "The dest is: " << endl;
    show(dest);
    cout << endl << "The number of comparisons is: " << nr_of_comparisons << endl;
    return 0;
}

