//
// Created by klimenko on 11.10.2017.
//

#include <iostream>
#include <algorithm>
#include "Sorter.h"

#include "SorterTest.h"

using namespace std;

template<typename T>
bool tests::SorterTest::TestFull( std::function<void(std::vector<T>&)> sorterFun ) {

    std::vector< std::vector<T> > etalons = {
             { 1, -1 }
            ,{ -1, 1 }
            ,{ 3, 1, -1 }
            ,{ 3, 1, -1, 20 }
            ,{ 7, 8, 4, 6, 7, 1, -1, 3, 10 }
    };
    for ( const auto& vec : etalons ) {
        bool res = TestOne( sorterFun, vec );
        if ( !res ) {
            return res;
        }
    }


    for ( int tc = 0; tc < 200; tc++ ) {
        std::vector<int> etalon = generate<int>();
        bool res = TestOne( sorterFun, etalon );
        if ( !res ) {
            return res;
        }
    }

    cerr << "SorterTest::TestFull() PASSED" << endl;

    return true;
}

template<typename T>
std::vector<T> tests::SorterTest::generate(size_t N) {
    if ( N == 0 ) {
        N = static_cast<size_t>( rand() % 100 );
    }
    vector<T> v( N );
    for ( auto& x : v ) {
        x = static_cast<T>( rand() );
    }
    return v;
}

template<typename T>
bool tests::SorterTest::TestOne(std::function<void(std::vector<T> &)> sorterFun, const std::vector<T>& etalon) {
    //cerr << endl << "------------------" << endl;
    //for( const auto& x : etalon ) {
    //    cerr << x << " ";
    //}
    //cerr << endl;

    std::vector<int> vecEtallon = etalon;
    std::vector<int> vec = vecEtallon;

    std::sort( vecEtallon.begin(), vecEtallon.end() );
    sorterFun(vec);
    //for( const auto& x : vec ) {
    //    cerr << x << " ";
    //}
    //cerr << endl;

    if ( vecEtallon != vec ) {
        cerr << "FAILED. Vector is" << endl;
        for( const auto& x : etalon ) {
            cerr << x << " ";
        }
        cerr << endl;
        return false;
    } else {
        //cerr << "PASSED!" << endl;
        return true;
    }
}
