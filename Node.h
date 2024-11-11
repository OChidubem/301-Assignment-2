#ifndef NODE_H
#define NODE_H

/**
 * @file Node.h
 * @author Chidubem Okoye
 * @class CSCI 301
 * @date 11/11/2024
 * @brief Definition of the Node class for a linked structure.
 * 
 * This template class represents a node in a linked list, holding an item of
 * any data type and a pointer to the next node in the list.
 * 
 * @tparam ItemType The data type of the item stored in the node.
 */

template<class ItemType>
class Node {
private:
    ItemType item;              ///< Data for the node
    Node<ItemType>* next;       ///< Pointer to the next node

public:
    /**
     * @brief Default constructor that creates an empty node.
     */
    Node();  

    /**
     * @brief Parametrized constructor that creates a node with a specified item and next node pointer.
     * 
     * @param anItem The item to store in the node.
     * @param nextNodePtr Pointer to the next node in the list, defaulted to nullptr.
     */
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr = nullptr);

    /**
     * @brief Sets the item stored in the node.
     * 
     * @param anItem The item to store in the node.
     */
    void setItem(const ItemType& anItem);

    /**
     * @brief Sets the pointer to the next node.
     * 
     * @param nextNodePtr Pointer to the next node in the list.
     */
    void setNext(Node<ItemType>* nextNodePtr);

    /**
     * @brief Retrieves the item stored in the node.
     * 
     * @return ItemType The item stored in the node.
     */
    ItemType getItem() const;

    /**
     * @brief Retrieves the pointer to the next node.
     * 
     * @return Node<ItemType>* Pointer to the next node.
     */
    Node<ItemType>* getNext() const;
};

#endif // NODE_H
