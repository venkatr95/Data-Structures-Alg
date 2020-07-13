#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
struct BinaryTree;
template<typename T>
struct Node {
    T                   m_value = T();
    Node<T>*            m_parent{nullptr};
    Node<T>*            m_left{nullptr};
    Node<T>*            m_right{nullptr};
    BinaryTree<T>*      m_tree{nullptr};
    Node(const T& v): m_value(v) {}
    Node(const T& v, Node<T> *const l, Node<T> *const r): m_value(v), m_left(l), m_right(r) {
        this->m_left->m_tree = this->m_right->m_tree = m_tree;
        this->m_left->m_parent = this->m_right->m_parent = this;
    }
    ~Node() { delete m_left; delete m_right; }
    void set_tree(BinaryTree<T> *t) {
        m_tree = t;
        if (m_left) m_left->set_tree(t);
        if (m_right) m_right->set_tree(t);
    }
};
template<typename T>
struct BinaryTree {
    Node<T>*        m_root = nullptr;
    BinaryTree(Node<T> *const r) : m_root{r} {
        m_root->set_tree(this);
    }
    ~BinaryTree() { delete m_root; }
    /* ---------------------------- Iterator Implementation ----------------------------- */
    template<typename U>
    struct PreOrderIterator {
        Node<U> *current;
        PreOrderIterator(Node<U> *c): current(c) {}
        bool operator!=(const PreOrderIterator<U>& rhs) { return current != rhs.current; }
        PreOrderIterator<U>& operator++() {
            if (current->m_right) {
                current = current->m_right;
                while (current->m_left)
                    current = current->m_left;
            } else {
                Node<T> *p = current->m_parent;
                while (p && current == p->m_right) {
                    current = p;
                    p = p->m_parent;
                }
                current = p;
            }
            return *this;
        }
        Node<U>& operator*() { return *current; }
    };
    using iterator = PreOrderIterator<T>;
    iterator begin() {
        Node<T> *n = m_root;
        if (n)
            while (n->m_left)
                n = n->m_left;
        return iterator{n};
    }
    iterator end() { return iterator{nullptr}; }
    /* ---------------------------------------------------------------------------------- */
};
int main() {
    //         me
    //        /  \
    //   mother   father
    //      / \
    //   m'm   m'f
    BinaryTree<string> family {
        new Node<string>{"me",
            new Node<string>{"mother",
                new Node<string>{"mother's mother"},
                new Node<string>{"mother's father"}
            },
            new Node<string>{"father"}
        }
    };
    for_each(begin(family), end(family), // Works with STL algo
    [](auto&& n) {
        cout << n.m_value << endl;
    });
    for (const auto& it: family) // Works with range-based for loop as well
        cout << it.m_value << endl;
    return EXIT_SUCCESS;
}
