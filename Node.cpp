/**
 * @file Node.cpp
 * @brief Implementation of the Node class for a linked structure.
 * @date 11/11/2024
 * @class CSCI 301
 * @author Chidubem Okoye
 *
 * This file implements the methods defined in the Node class template, including
 * constructors, accessor, and mutator methods. The Node class represents a
 * node in a linked list, storing an item and a pointer to the next node.
 */

#include "Node.h"
#include <string>

/**
 * @brief Default constructor that initializes the node with a nullptr for the next pointer.
 */
template<class ItemType>
Node<ItemType>::Node() : next(nullptr) {}

/**
 * @brief Parametrized constructor that initializes the node with an item and a pointer to the next node.
 * 
 * @param anItem The item to store in the node.
 * @param nextNodePtr Pointer to the next node in the list.
 */
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr)
    : item(anItem), next(nextNodePtr) {}

/**
 * @brief Sets the item stored in the node.
 * 
 * @param anItem The item to store in the node.
 */
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

/**
 * @brief Sets the pointer to the next node.
 * 
 * @param nextNodePtr Pointer to the next node in the list.
 */
template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
    next = nextNodePtr;
}

/**
 * @brief Retrieves the item stored in the node.
 * 
 * @return ItemType The item stored in the node.
 */
template<class ItemType>
ItemType Node<ItemType>::getItem() const {
    return item;
}

/**
 * @brief Retrieves the pointer to the next node.
 * 
 * @return Node<ItemType>* Pointer to the next node.
 */
template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
    return next;
}

// Explicit template instantiations if needed
template class Node<int>;          ///< Explicit instantiation for int type
template class Node<double>;       ///< Explicit instantiation for double type
template class Node<std::string>;  ///< Explicit instantiation for std::string type
