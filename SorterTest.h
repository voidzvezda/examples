//
// Created by klimenko on 11.10.2017.
//

#ifndef EXAMPLES_SORTERTEST_H
#define EXAMPLES_SORTERTEST_H

#include <vector>
#include <functional>

namespace tests {
    struct SorterTest {
        template<typename T>
        static bool TestFull( std::function<void(std::vector<T>&)> );
    private:
        template<typename T>
        static std::vector<T> generate( size_t N = 0 );

        template<typename T>
        static bool TestOne( std::function<void(std::vector<T>&)>, const std::vector<T>& );
    };
}


#endif //EXAMPLES_SORTERTEST_H
