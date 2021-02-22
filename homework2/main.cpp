#include <iostream>
#include "polynomial.h"
#include <sstream>
#include <assert.h>

using namespace std;

void checkOut() {
    stringstream ss;
    ss << Polynomial(0, 2, new int[3]{1, 2, 3}) << " ";
    ss << Polynomial(1, 2, new int[2]{-3, 4}) << " ";
    ss << Polynomial(-1, 2, new int[4]{1, -3, 0, -1}) << " ";
    ss << Polynomial() << " ";
    ss << Polynomial(0, 2, new int[3]{0, 3, -3}) << " ";
    ss << Polynomial(-2, 2, new int[5]{1, 0, 0, 0, 1}) << " ";
    cout << ss.str();
    assert(ss.str() == "x^2+2x+1 x^2-3x -x^2-3+x^-1 0 -x^2+3x x^2+x^-2 ");
}

int main() {
    checkOut();
    return 0;
}
