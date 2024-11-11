/**
 * @file LinkedStack.cpp
 * @brief Implementation of the LinkedStack class for a stack data structure using linked nodes.
 * @date 11/11/2024
 * @class CSCI 301
 * @author Chidubem Okoye
 * 
 * This file implements the methods of the LinkedStack class, which represents a stack
 * with common operations such as push, pop, and peek. The stack is implemented using
 * a linked list structure, where each node points to the next node in the stack.
 */

#include "LinkedStack.h"
#include <cassert>
#include <string>

/**
 * @brief Default constructor that initializes an empty stack.
 */
template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr) {}

/**
 * @brief Copy constructor that creates a deep copy of an existing stack.
 * 
 * @param originalStack The stack to be copied.
 */
template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& originalStack) {
    auto originalChainPtr = originalStack.topPtr;
    if (originalChainPtr == nullptr) {
        topPtr = nullptr;
    } else {
        topPtr = new Node<ItemType>(originalChainPtr->getItem());
        auto myChainTailPtr = topPtr;
        originalChainPtr = originalChainPtr->getNext();
        while (originalChainPtr != nullptr) {
            auto nextItem = originalChainPtr->getItem();
            auto itemNodePtr = new Node<ItemType>(nextItem);
            myChainTailPtr->setNext(itemNodePtr);
            myChainTailPtr = myChainTailPtr->getNext();
            originalChainPtr = originalChainPtr->getNext();
        }
        myChainTailPtr->setNext(nullptr);
    }
}

/**
 * @brief Destructor that deallocates all nodes in the stack.
 */
template<class ItemType>
LinkedStack<ItemType>::~LinkedStack() {
    while (!isEmpty()) {
        pop();
    }
}

/**
 * @brief Checks if the stack is empty.
 * 
 * @return true if the stack is empty, false otherwise.
 */
template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const noexcept {
    return topPtr == nullptr;
}

/**
 * @brief Adds an item to the top of the stack.
 * 
 * @param someItem The item to push onto the stack.
 * @return true if the item was successfully added.
 */
template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& someItem) {
    auto itemNodePtr = new Node<ItemType>(someItem, topPtr);
    topPtr = itemNodePtr;
    return true;
}

/**
 * @brief Removes the top item from the stack.
 * 
 * @return true if the top item was successfully removed, false if the stack was empty.
 */
template<class ItemType>
bool LinkedStack<ItemType>::pop() noexcept {
    bool result = false;
    if (!isEmpty()) {
        auto nodeToDeletePtr = topPtr;
        topPtr = topPtr->getNext();
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        result = true;
    }
    return result;
}

/**
 * @brief Retrieves the top item of the stack without removing it.
 * 
 * @return ItemType The item at the top of the stack.
 * @throws std::runtime_error if the stack is empty.
 */
template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const {
    assert(!isEmpty());
    return topPtr->getItem();
}

// Explicit template instantiations if needed
template class LinkedStack<int>;       ///< Explicit instantiation for int type
template class LinkedStack<double>;    ///< Explicit instantiation for double type
template class LinkedStack<std::string>;  ///< Explicit instantiation for std::string type
