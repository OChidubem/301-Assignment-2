#ifndef LINKED_STACK_H
#define LINKED_STACK_H

/**
 * @file LinkedStack.h
 * @brief Definition of the LinkedStack class for a stack data structure using linked nodes.
 * @date 11/11/2024
 * @class CSCI 301
 * @author Chidubem Okoye
 * 
 * This template class implements a stack using a linked list structure, where each
 * node points to the next node in the stack. The stack supports common operations
 * such as push, pop, peek, and checking if the stack is empty.
 * 
 * @tparam ItemType The data type of the items stored in the stack.
 */

#include "StackInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType> {
private:
    Node<ItemType>* topPtr;  ///< Pointer to the top node in the stack

public:
    /**
     * @brief Default constructor that initializes an empty stack.
     */
    LinkedStack();

    /**
     * @brief Copy constructor that creates a deep copy of an existing stack.
     * 
     * @param originalStack The stack to be copied.
     */
    LinkedStack(const LinkedStack<ItemType>& originalStack);

    /**
     * @brief Destructor that deallocates all nodes in the stack.
     */
    virtual ~LinkedStack();

    /**
     * @brief Checks if the stack is empty.
     * 
     * @return true if the stack is empty, false otherwise.
     */
    bool isEmpty() const noexcept override;

    /**
     * @brief Adds an item to the top of the stack.
     * 
     * @param someItem The item to push onto the stack.
     * @return true if the item was successfully added, false otherwise.
     */
    bool push(const ItemType& someItem) override;

    /**
     * @brief Removes the top item from the stack.
     * 
     * @return true if the top item was successfully removed, false if the stack was empty.
     */
    bool pop() noexcept override;

    /**
     * @brief Retrieves the top item of the stack without removing it.
     * 
     * @return ItemType The item at the top of the stack.
     * @throws std::runtime_error if the stack is empty.
     */
    ItemType peek() const override;
};

#endif // LINKED_STACK_H
