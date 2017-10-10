//
// Created by klimenko on 10.10.2017.
//

#ifndef EXAMPLES_STACK_H
#define EXAMPLES_STACK_H

#include <cstdint>
#include <stdexcept>

namespace voidstl {

    template <typename Tp>
    class Stack {
    private:
        struct Element {
            Element(Tp *valuePtr, Element *link = nullptr) : valuePtr(valuePtr), link(link) {
            }

            ~Element() {
                if (valuePtr) {
                    delete valuePtr;
                }
            }

            Tp* valuePtr;
            Element* link;

        };

    private:
        Element* topPtr;
        size_t size;

    public:
        Stack() : topPtr( nullptr ), size(0) {}

        size_t depth() const {
            return size;
        }

        void push( const Tp& newValue ) {
            Element* newElementPtr =  new Element( new Tp(newValue), topPtr );
            topPtr = newElementPtr;
            size++;
        }

        Tp pop() {
            if ( topPtr ) {
                Element* topElementPtr = topPtr;
                topPtr = topPtr->link;
                size--;
                Tp value = *topElementPtr->valuePtr;
                delete topElementPtr;
                return value;
            } else {
                throw std::out_of_range( "pop(): Stack is empty" );
            }
        }

        const Tp& top() const {
            if ( topPtr ) {
                return *topPtr->valuePtr;
            } else {
                throw std::out_of_range( "top(): Stack is empty" );
            }
        }

    };

} // namespace voidstl


#endif //EXAMPLES_STACK_H
