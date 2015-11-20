#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>

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

int remove_sort_dup (vector<char>& source, vector<char>& dest)
{// pre-condition:
    assert (size (dest) == 0 && is_sorted (source)) ;
// post-condition: dest is a copy of source without duplicate elements
// result is the number of comparisons performed in this function
    char prev_char = '\0';

    for (char curr_char : source) {
        if (prev_char != curr_char){
            dest.push_back(curr_char);
            prev_char = curr_char;
        }
    }
}

void fill(string txt, vector<char> &r) {// pre-condition:
    assert (size(r) == 0);
//  post-condition: r contains all characters of txt
    for (int i = 0; i < txt.size(); i++)
        r.push_back(txt[i]);
}

void show(vector<char> &r) {// pre-condition:
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

