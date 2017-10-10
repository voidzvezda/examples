//
// Created by klimenko on 10.10.2017.
//

#include <iostream>
#include "Stack.h"
#include "StackTest.h"

using namespace voidstl;
using namespace std;

bool tests::StackTest::TestFull() {
    int normalErrorCount      = 0;
    int unexpectedErrorsCount = 0;
    try {
        Stack<int> s;
        s.push(5);
        s.push(4);
        s.push(3);
        s.push(2);
        s.push(1);

        if (s.showTop() != 1 ) {
            cerr << "showTop() error" << endl;
            unexpectedErrorsCount++;
        }

        for ( int i = 0; i < 5; i++ ) {
            cerr << "pop " << s.pop() << endl;
        }

        try {
            cerr << "Making an error" << endl;
            s.pop();
        } catch (out_of_range& e) {
            cerr << "Got an expected error" << endl;
            normalErrorCount++;
        }

        try {
            cerr << "Making an error" << endl;
            int x = s.showTop();
            cerr << "can't happen" << x << endl;
        } catch (out_of_range& e) {
            cerr << "Got an expected error" << endl;
            normalErrorCount++;
        }

        s.push(100);
        s.push(101);

        if ( s.depth() != 2 ) {
            unexpectedErrorsCount++;
        }

    } catch (out_of_range& e) {
        cerr << "Got an unexpected error: " << e.what() << endl;
        unexpectedErrorsCount++;
    }

    if ( normalErrorCount == 2 && unexpectedErrorsCount == 0 ) {
        return true;
    } else {
        return false;
    }
}
