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

        class Element;
        using ElementPtr = std::shared_ptr<Element>;
        using TpPtr      = std::unique_ptr<Tp, Dtr>;

        class Element {
        public:
            explicit Element(TpPtr&& valuePtr, ElementPtr link = nullptr)
                : valuePtr( move(valuePtr) ), link(link) {}

            const Tp& getValue() const {
                return *valuePtr;
            }

            const ElementPtr& getLink() const {
                return link;
            }

        private:
            const TpPtr valuePtr;
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

        Tp pop() {
            if ( topPtr ) {
                Tp value = topPtr->getValue(); // Save value for return.
                topPtr = topPtr->getLink(); // Change 'top' to the next element in the stack.
                size--;
                return value;
            } else {
                throw std::out_of_range( "pop(): Stack is empty" );
            }
        }

        // Seems unsafe: reference can become invalid.
        // Should change to return the copy of a value?
        const Tp& showTop() const {
            if ( topPtr ) {
                return topPtr->getValue();
            } else {
                throw std::out_of_range( "showTop(): Stack is empty" );
            }
        }

    };

} // namespace voidstl


#endif //EXAMPLES_STACK_H
