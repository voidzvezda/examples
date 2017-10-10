#include <iostream>

#include "StackTest.h"

using namespace std;

int main() {
    cerr << "BEGIN" << endl;

    tests::StackTest::TestFull();

    cerr << "END" << endl;
    return 0;
}