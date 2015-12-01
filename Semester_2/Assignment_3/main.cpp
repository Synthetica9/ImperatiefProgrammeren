#include <iostream>
#include <assert.h>
#include <vector>
#include <tuple>
#include <algorithm>
#include <ctime>

// RAII timer from http://felix.abecassis.me/2011/09/cpp-timer-raii/
// Definitely stealing this for future use.
class Timer {
public:
    Timer(const std::string &name)
            : name_(name),
              start_(std::clock()) {
    }

    ~Timer() {
        double elapsed = (double(std::clock() - start_) / double(CLOCKS_PER_SEC));
        std::cout << name_ << ": " << int(elapsed * 1000) << "ms" << std::endl;
    }

private:
    std::string name_;
    std::clock_t start_;
};

void test_sort();

void test_various();

void time_fib();

#define TIMER(name) Timer timer__(name);

using namespace std;

template<typename T>
int v_size(vector<T> v) {
    return int(v.size());
}

int sum(int n) {
    // Pre-condition:
    assert(n >= 0);
    // Post-condition:
    // Returns n + n-1 + ... + 2 + 1
    return n > 0 ? n + sum(n - 1) : 0;
    // return ((n - 1) * n) / 2 // Wait, what?
}

int power(int x, int n) {
    // Pre-condition:
    assert(n >= 0);
    // Post-condition
    // Returns x * x * ... * x * x (n times)
    if (n == 0)
        return 1;

    int p = power(x, n / 2);
    p *= p;

    if (n % 2 != 0)
        p *= x;

    return p;
}

template<typename T>
T minimum(vector<T> &a, int n) {
    // Pre-condition:
    assert(n >= 0 && n <= v_size(a));
    // Post-condition:
    // Returns min(a)
    return n > 1 ? min(a[n - 1], minimum(a, n - 1)) : a[0];
}

int gcd(int a, int b) {
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Too lazy to open the previous assignment
template<typename T>
void selection_sort(vector<T> &a, int n) {
    // n > 1, because an array of length 1 is always sorted
    if (n > 1) {
        int current_max = 0;
        for (int i = 1; i < n; ++i)
            if (a[current_max] < a[i])
                current_max = i;

        swap(a[n - 1], a[current_max]);
        selection_sort(a, n - 1);
    }
}

template<typename T>
void selection_sort(vector<T> &a) {
    selection_sort(a, v_size(a));
}

/* The naive function:

fib(N) = N <= 1 ? N : fib(N-1) + fib(N-2)

 * This function has complexity O(fib(N)), because every "unity part" originates as a function call4
 *
 * Based on the "Fast doubling" implementation discussed here: http://www.nayuki.io/page/fast-fibonacci-algorithms
 * Made tail-recursive instead of head-recursive to allow for actual constant-memory operation at the cost of (haven't
 * actually checked this, it might be faster than the original implementation) a constant time and memory factor.
 * Since this runs in O(log N), you'll have to imagine in some extra work by yourself to make it O(N).
 * This is the original implementation, I think ours differs enough from it to count as a separate solution:
 * (I'm starting to get the feeling I overthought this.)

# (Public) Returns F(n).
def fibonacci(n):
    if n < 0:
        raise ValueError("Negative arguments not implemented")
    return _fib(n)[0]


# (Private) Returns the tuple (F(n), F(n+1)).
def _fib(n):
    if n == 0:
        return (0, 1)
    else:
        a, b = _fib(n // 2)
        c = a * (b * 2 - a)
        d = a * a + b * b
        if n % 2 == 0:
            return (c, d)
        else:
            return (d, c + d)


 * This implementation, unlike the original, uses O(N) memory (assuming that tail-recursion gets optimized away, but
 * I think it is impossible to write a O(1) memory function without this assumption). This is at the cost of doing all
 * shifts twice, once to see how many times you should do it, and once to actually calculate the next result. There is a
 * single assembly instruction to do this, but this is not consistently defined across platforms,  so we have to hope
 * that this is optimized by the compiler (I don't think most compilers will do this, but one can hope.)
 */

template <typename arg_T, typename ret_T>
ret_T naive_fib(arg_T n) {
    if (n == 0 || n == 1)
        return ret_T(n);

    return naive_fib<arg_T, ret_T>(n - 1) + naive_fib<arg_T, ret_T>(n - 2);
};

template <typename arg_ret_T>
arg_ret_T naive_fib(arg_ret_T n) {
    return naive_fib<arg_ret_T, arg_ret_T>(n);
}

template<typename arg_T, typename ret_T>
ret_T fib_doubling(arg_T n, arg_T m, ret_T a = 0, ret_T b = 1) {
    assert(n >= 0);
    assert(b >= a);
    assert(m >= -1);
    assert(a >= 0);
    assert(b >= 1);

    if (m == -1)
        return a;

    ret_T c = a * (b * 2 - a);
    ret_T d = a * a + b * b;

    ret_T next_a, next_b;
    if ((n >> m) % 2 == 0) {
        next_a = c;
        next_b = d;
    } else {
        next_a = d;
        next_b = c + d;
    }

    fib_doubling(n, m - 1, next_a, next_b);
}

template<typename arg_ret_T>
arg_ret_T log_2(arg_ret_T n, arg_ret_T m = 0) {
    assert(n >= 0 && m >= 0);
    if (n >> m == 0)
        return m;

    return log_2<arg_ret_T>(n, m + 1);
}

template<typename arg_T, typename ret_T>
ret_T fib(arg_T n) {
    assert(n >= 0);
    arg_T m = log_2(n);
    return fib_doubling<arg_T, ret_T>(n, m);
}

// Make sure simple calls work:
template<typename arg_ret_T>
arg_ret_T fib(arg_ret_T n) {
    assert(n >= 0);
    return fib<arg_ret_T, arg_ret_T>(n);
}

template<typename T>
ostream &operator<<(ostream &s, vector<T> &v) {
    s << '{';
    for (T element : v) {
        s << element << ", ";
    }
    s << '}';
    return s;
}

template<typename T>
void random_shuffle(vector<T> &v) {
    random_shuffle(v.begin(), v.end());
}

void time_fib() {
    {
        vector<double> v;
        TIMER("Naive Fibonachi: 40 iterations")
        for (int i = 0; i < 40; i++){
            v.push_back(naive_fib<int, double>(i));
        }
    }

    {
        vector<double> v;
        TIMER("Speedy Fibonachi: 100000 iterations")
        for (int i = 0; i < 100000; i++){
            v.push_back(fib<int, double>(i % 1400));
        }
    }

    /*
     * Output (in case your compiler does too much optimization:
     * Naive Fibonachi: 40 iterations: 697ms
     * Speedy Fibonachi: 100000 iterations: 8ms
     * Yeah, that's some quite serious improvement
     */
}

void test_various() {
    cout <<
    "fib(45): " << fib(45) << endl <<
    "fib(100) (using int > double conversion to prevent overflow): " << fib<int, double>(100) << endl <<
    "fib(1400) (dito): " << fib<int, double>(1400) << endl <<
    "sum(20): " << sum(20) << endl <<
    "gcd(5250, 27720): " << gcd(5250, 27720) << endl;
}

void test_sort() {
    vector<int> test_vector;
    for (int i = 0; i < 40; ++i) {
        int v = fib(i);
        test_vector.push_back(v);
    }

    cout << "Selection sort test: " << endl;
    cout << test_vector << endl;
    random_shuffle(test_vector);
    cout << test_vector << endl;
    selection_sort(test_vector);
    cout << test_vector << endl;
}

int main() {
    test_sort();

    test_various();

    time_fib();



    return 0;
}
