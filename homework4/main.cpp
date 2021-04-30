#include "predicate.hpp"
#include <iostream>
#include <sstream>
#include <assert.h>
#include <vector>
#include <set>
#include <iterator>
#include <functional>


using namespace std;

class myForwardIterator : public vector<int>::iterator {
    using T = vector<int>::iterator;
    using T::T;
public:

    auto operator--(int) const = delete;
    auto operator--() const = delete;
    auto operator-(difference_type __n) const = delete;
    myForwardIterator(vector<int>::iterator it) : T(it){}
};


void check() {
	vector<int> a{1, 2, 3, 4};
	vector<int> b{1, 2, 3, 4, 2};
	vector<int> c{4, 3, 2, 1, 0};
	vector<int> d{1, 1};
	vector<int> e{1, 2, 3, 4, 3, 2, 1};
	vector<int> f{1, 2, 3, 4, 3, 2, 3};
	vector<int> e1{1, 2, 3, 3, 2, 1};
	vector<int> f1{1, 2, 3, 4, 2, 1};
	vector<pair<int ,int>> h{{1, 2}, {2, 3}, {3, 4}};




	vector<int> g{1};
	set<int> s{1, 2, 3};

	assert(allOf(a.begin(), a.end(), [](int x){return x <= 5;}));
	assert(!allOf(a.begin(), a.end(), [](int x){return x <= 3;}));
	assert(anyOf(a.begin(), a.end(), [](int x){return x == 3;}));
	assert(!anyOf(a.begin(), a.end(), [](int x){return x == 5;}));
	assert(noneOf(a.begin(), a.end(), [](int x){return x > 5;}));
	assert(!noneOf(a.begin(), a.end(), [](int x){return x >= 3;}));
	assert(oneOf(b.begin(), b.end(), [](int x){return x == 3;}));
	assert(!oneOf(b.begin(), b.end(), [](int x){return x == 2;}));
	assert(isSorted(a.begin(), a.end(), [](int x, int y){return x < y;}));
	assert(!isSorted(b.begin(), b.end(), [](int x, int y){return x < y;}));
	assert(isSorted(a.begin(), a.end()));
	assert(!isSorted(b.begin(), b.end()));
	assert(isSorted(c.begin(), c.end(), [](int x, int y){return x > y;}));
	assert(isPartitioned(a.begin(), a.end(), [](int x){return x <= 3;}));
	assert(!isPartitioned(a.begin(), a.end(), [](int x){return x % 2 == 0;}));
	assert(isPartitioned(a.begin(), a.end(), [](int x){return x <= 3;}));
	assert(findNot(a.begin(), a.end(), 1) == ++a.begin());	
	assert(findNot(d.begin(), d.end(), 1) == d.end());	
	assert(findBackward(static_cast<myForwardIterator>(b.begin()), static_cast<myForwardIterator>(b.end()), 2) == --b.end());
	assert(findBackward(static_cast<myForwardIterator>(b.begin()), static_cast<myForwardIterator>(b.end()), 5) == b.end());
	assert(isPalindrome(e.begin(), e.end(), [](int x, int y){return x == y;}));
	assert(!isPalindrome(f.begin(), f.end(), [](int x, int y){return x == y;}));
	assert(isPalindrome(e1.begin(), e1.end(), [](int x, int y){return x == y;}));
	assert(!isPalindrome(f1.begin(), f1.end(), [](int x, int y){return x == y;}));
	assert(isPalindrome(s.begin(), s.end(), [](int x, int y){return x + y > 0;}));
	assert(isPalindrome(g.begin(), g.end(), [](int x, int y){return x == y;}));
	assert(isSorted(h.begin(), h.end(), [](pair<int, int> x, pair<int, int> y) {return x < y;}));
	assert(isSorted(h.begin(), h.end()));
}
int main() {
    check();
}
