//
// Created by klimenko on 10.10.2017.
//

#ifndef EXAMPLES_STACKTEST_H
#define EXAMPLES_STACKTEST_H

namespace tests {
    class StackTest {
    public:
        static bool TestFull();
    private:
        struct NoCopyCtrClass {
            NoCopyCtrClass() = default;
            NoCopyCtrClass( const NoCopyCtrClass& ) = delete;
            NoCopyCtrClass( NoCopyCtrClass&& ) noexcept {}
        };

        struct NoDefaultCtrClass {
            NoDefaultCtrClass() = delete;
            explicit NoDefaultCtrClass(int){}
        };
    };
}


#endif //EXAMPLES_STACKTEST_H
