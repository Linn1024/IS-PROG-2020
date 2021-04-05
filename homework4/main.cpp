#include "predicate.hpp"
#include <iostream>
#include <sstream>
#include <assert.h>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

void check() {
	vector<int> a{1, 2, 3, 4};
	vector<int> b{1, 2, 3, 4, 2};
	vector<int> c{4, 3, 2, 1, 0};
	vector<int> d{1, 1};


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
	assert(isSorted(c.begin(), c.end(), [](int x, int y){return x > y;}));
	assert(isPartitioned(a.begin(), a.end(), [](int x){return x <= 3;}));
	assert(!isPartitioned(a.begin(), a.end(), [](int x){return x % 2 == 0;}));
	assert(isPartitioned(a.begin(), a.end(), [](int x){return x <= 3;}));
	assert(findNot(a.begin(), a.end(), 1) == ++a.begin());	
	assert(findNot(d.begin(), d.end(), 1) == d.end());	
	assert(findBackward(b.begin(), b.end(), 2) == --b.end());
}


int main() {
    check();
}
