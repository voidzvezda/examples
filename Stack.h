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
    template< typename Tp >
    class Stack {
    protected:

        struct Element;
        using ElementPtr = std::shared_ptr<Element>;

        struct Element {
            explicit Element(const Tp& value, ElementPtr link) noexcept
                    : value( value ), link(link) {}

            explicit Element(Tp&& value, ElementPtr link) noexcept
                    : value( std::move(value) ), link(link) {}

            template<typename... Args>
            explicit Element(ElementPtr link, Args&&... args) noexcept
            : value( std::forward<Args>(args)... ), link(link){}

            Tp value;
            const ElementPtr link;
        };

        ElementPtr topPtr;
        size_t size;

    protected:
        void push( ElementPtr newElementPtr ) {
            topPtr = newElementPtr;
            size++;
        }

    public:
        Stack() noexcept
            : topPtr( nullptr ), size(0) {}


        size_t depth() const {
            return size;
        }

        void push( const Tp& newValue ) {
            push( std::make_shared<Element>( newValue, topPtr ) );
        }

        void push( Tp&& newValue ) {
            push( std::make_shared<Element>( std::move(newValue), topPtr ) );
        }

        template<typename... Args>
        void emplace( Args&&... args ) {
            push( std::make_shared<Element>( topPtr, std::forward<Args>(args)... ) );
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
                return topPtr->value;
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
