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

    template<typename T>
    static void btree(std::vector<T> &vec) {
        TreeHelper<T> helper;
        auto& bst = helper.bst;
        for ( const auto& val : vec ) {
            bst.Add( val );
        }
        std::vector<T> v;
        v.reserve(vec.size());
        bst.traverseLeft(v);

        vec = v;
    }

private:

    template<typename T>
    struct TreeHelper {

        struct Node;
        using NodePtr = Node*;
        struct Node {
            Node( const T& value ) : left(nullptr), right(nullptr), value(value) {}
            NodePtr left;
            NodePtr right;
            T value;
        };

        class BinarySearchTree {
        public:
            BinarySearchTree() : root( nullptr ) {}
            void Add( const T& value ) {
                root = Add( root, value );
            }

            void traverseLeft(std::vector<T>& v) {
                traverseLeft(root, v);
            }

        private:
            NodePtr Add( NodePtr node, const T& value ) {
                if ( !node ) {
                    NodePtr newNode( new Node( value ) );
                    return newNode;
                }

                if ( value >= node->value ) {
                    node->right = Add( node->right, value );
                } else {
                    node->left  = Add( node->left, value );
                }
                return node;
            }

            void traverseLeft( NodePtr node, std::vector<T>& v ) {
                if ( node ) {
                    traverseLeft( node->left, v );
                    v.push_back( node->value );
                    traverseLeft( node->right, v );
                }
            }
            NodePtr root;
        };

        BinarySearchTree bst;
    };

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
