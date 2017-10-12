//
// Created by klimenko on 11.10.2017.
//

#ifndef EXAMPLES_SORTER_H
#define EXAMPLES_SORTER_H

#include <cstdint>
#include <vector>

#include <iostream>
using namespace std;

struct Sorter {

    template<typename T>
    static void bubble(std::vector<T> &vec) {
        const int N = (int)vec.size();
        for ( int i = 0; i < N; ++i ) {
            for ( int j = 0; j < N-1; j++ ) {
                if ( vec[i]<vec[j] ) {
                    std::swap(vec[i], vec[j]);
                }
            }
        }
    }

    template<typename T>
    static void quick(std::vector<T> &vec) {
        QSortHelper<T>::qsortRecursive( vec, 0, vec.size() - 1 );
    }

private:

    template< typename T >
    struct QSortHelper {

        static void qsortRecursive( std::vector<T>& v, int L, int R ) {

            if ( L != R ) {
                const T& sep = qsortGetSeparative( v, L, R );
                int left = L;
                int right = R;
                while ( left != right  ) {

                    if ( v[left] <= sep ) {
                        left++;
                    } else {
                        while ( left != right && sep < v[right] ) {
                            right--;
                        }
                        std::swap( v[left], v[right] );
                    }

                }

                left--;

                qsortRecursive( v, L, left );
                qsortRecursive( v, right, R );
            }

        }

        static T qsortGetSeparative( std::vector<T>& v, int L, int R ) {
            return v[R];
        }
    };

};



#endif //EXAMPLES_SORTER_H
