//
// Created by klimenko on 10.10.2017.
//

#ifndef EXAMPLES_STACK_H
#define EXAMPLES_STACK_H

#include <cstdint>
#include <stdexcept>
#include <memory>

namespace voidstl {

    /*
     * Simple Stack example.
     */
    template< typename Tp, class Dtr = std::default_delete<Tp> >
    class Stack {
    private:

        struct Element;
        using ElementPtr = std::shared_ptr<Element>;
        using TpPtr      = std::unique_ptr<Tp, Dtr>;

        struct Element {
            explicit Element(TpPtr&& valuePtr, ElementPtr link = nullptr)
                : valuePtr( move(valuePtr) ), link(link) {}

            TpPtr valuePtr;
            const ElementPtr link;
        };


    private:
        ElementPtr topPtr;
        size_t size;

    public:
        Stack() : topPtr( nullptr ), size(0) {}

        size_t depth() const {
            return size;
        }

        void push( const Tp& newValue ) {
            ElementPtr newElementPtr(
                    new Element(
                            TpPtr( new Tp(newValue) ),
                            topPtr
                    )
            );
            topPtr = newElementPtr;
            size++;
        }

        void pop() {
            if ( topPtr ) {
                topPtr = topPtr->link; // Change 'top' to the next element in the stack.
                size--;
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

        Tp& top() {
            return const_cast<Tp&>( static_cast<const Stack*>(this)->top() );
        }

    };

} // namespace voidstl


#endif //EXAMPLES_STACK_H
