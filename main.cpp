#include <iostream>

#include "StackTest.h"
#include "SorterTest.h"
#include "Sorter.h"

#include "SorterTest.cpp"


using namespace std;

int main() {
    cerr << "BEGIN" << endl;

    //tests::StackTest::TestFull();
    //tests::SorterTest::TestFull<int>( &Sorter::bubble<int> );
    //tests::SorterTest::TestFull<int>( &Sorter::quick<int> );
    tests::SorterTest::TestFull<int>( &Sorter::btree<int> );

    cerr << "END" << endl;
    return 0;
}