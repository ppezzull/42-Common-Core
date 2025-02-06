#include <iostream>
#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Iterating through the stack:" << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << "Reverse iteration:" << std::endl;

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << "Testing const iterators:" << std::endl;

    const MutantStack<int> constMstack = mstack;

    for (MutantStack<int>::const_iterator cit = constMstack.begin(); cit != constMstack.end(); ++cit) {
        std::cout << *cit << std::endl;
    }

    return 0;
}
