#ifndef STACK_INTERFACE_
#define STACK_INTERFACE_

/**
 * @file StackInterface.h
 * @brief Interface for a generic stack data structure.
 * @date 11/11/2024
 * @class CSCI 301
 * @author Chidubem Okoye
 * 
 * This file defines a pure virtual interface for a stack. It provides the essential
 * operations for a stack, such as checking if it is empty, pushing an item onto the stack,
 * popping the top item, and peeking at the top item without removing it. Derived classes
 * must implement these operations.
 * 
 * @tparam ItemType The data type of the items to be stored in the stack.
 */

template<class ItemType>
class StackInterface {
public:
    /**
     * @brief Checks if the stack is empty.
     * 
     * @return true if the stack is empty, false otherwise.
     */
    virtual bool isEmpty() const noexcept = 0;

    /**
     * @brief Pushes an item onto the stack.
     * 
     * @param someItem The item to be pushed onto the stack.
     * @return true if the item was successfully pushed, false otherwise.
     */
    virtual bool push(const ItemType& someItem) = 0;

    /**
     * @brief Pops the top item from the stack.
     * 
     * @return true if the item was successfully popped, false otherwise.
     */
    virtual bool pop() noexcept = 0;

    /**
     * @brief Peeks at the top item of the stack without removing it.
     * 
     * @return The top item of the stack.
     * @throws std::runtime_error if the stack is empty.
     */
    virtual ItemType peek() const = 0;

    /**
     * @brief Virtual destructor to allow proper cleanup of derived classes.
     */
    virtual ~StackInterface() {}
};

#endif // STACK_INTERFACE_
