//
// Created by klimenko on 10.10.2017.
//

#include <iostream>
#include "Stack.h"
#include "StackTest.h"

using namespace voidstl;
using namespace std;

bool tests::StackTest::TestFull() {

    int expectedErrorsCount   = 0;
    int gotNormalErrorCount   = 0;
    int unexpectedErrorsCount = 0;

    try {
        Stack<int> s;

        for ( int i = 5; i > 0; --i ) {
            s.push(i);
        }

        if (s.top() != 1 ) {
            cerr << "top() error" << endl;
            unexpectedErrorsCount++;
        }

        for ( int i = 1; i < 6; i++ ) {
            int& x = s.top();
            if ( x != i ) {
                unexpectedErrorsCount++;
            }

            x = 13;
            if ( s.top() != 13 ) {
                unexpectedErrorsCount++;
            }

            const int& cx = s.top();
            cerr << cx;

            s.pop();
            cerr << " pop " << " ";
        }
        cerr << endl;

        expectedErrorsCount++;
        try {
            cerr << "Making an error" << endl;
            s.pop();
        } catch (out_of_range& e) {
            cerr << "   Got an expected error" << endl;
            gotNormalErrorCount++;
        }

        expectedErrorsCount++;
        try {
            cerr << "Making an error" << endl;
            int x = s.top();
            cerr << "can't happen" << x << endl;
            unexpectedErrorsCount++;
        } catch (out_of_range& e) {
            cerr << "   Got an expected error" << endl;
            gotNormalErrorCount++;
        }

        s.push(100);
        s.push(101);

        if ( s.depth() != 2 ) {
            unexpectedErrorsCount++;
        }

        const auto& sf = s;
        sf.top();

        {
            Stack<NoCopyCtrClass> nocpys;
            nocpys.push( NoCopyCtrClass() );
            auto& x = nocpys.top();
            const auto& cx = nocpys.top();
            nocpys.pop();
        }

        {
            Stack<NoDefaultCtrClass> nodefctr;
            nodefctr.push( NoDefaultCtrClass(1) );
            auto& x = nodefctr.top();
            const auto& cx = nodefctr.top();
            nodefctr.pop();
        }


    } catch (out_of_range& e) {
        cerr << "Got an unexpected error: " << e.what() << endl;
        unexpectedErrorsCount++;
    }

    cerr << unexpectedErrorsCount << " " << gotNormalErrorCount << " " << expectedErrorsCount << endl;

    if ( gotNormalErrorCount == expectedErrorsCount && unexpectedErrorsCount == 0 ) {
        cerr << "[ Test OK ]" << endl;
        return true;
    } else {
        cerr << "[ Test FAILED ]" << endl;
        return false;
    }
}
