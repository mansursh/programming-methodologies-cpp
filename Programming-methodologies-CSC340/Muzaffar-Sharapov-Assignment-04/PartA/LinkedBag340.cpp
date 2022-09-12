//	LinkedBag340.cpp
//	Created by: CSC340

/*
===>					<===
===>  PLEASE ADD CODE	<===
===>					<===
*/


#include <iostream>
#include <ctime>
#include "Node.h"
#include "LinkedBag.h"

template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {

    Node<ItemType> *getSecondNode = headPtr->getNext(); //gets the pointer to second node
    Node<ItemType> *getThirdNode = getSecondNode->getNext(); //gets the pointer to the third node
    headPtr->setNext(getThirdNode); //here we set head to third node and skipping second node
    return remove(getSecondNode->getItem()); //here we use remove method from linkedbag.cpp to delete second node
}

template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry) {
    Node<ItemType>* nextNodePtr{ new Node<ItemType>(newEntry) };	// constructor sets next to nullptr
    Node<ItemType>* tempPtr{ headPtr };
    while (tempPtr->getNext() != nullptr) {
        tempPtr = tempPtr->getNext();
    }
    tempPtr->setNext(nextNodePtr);
    nextNodePtr = nullptr;
    itemCount++;
    return true;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    if (headPtr == nullptr) {
        return 0;
    }
    Node<ItemType>* tempPtr{ headPtr };
    int count = 1;
    bool boolL = true;
    while (boolL) {
        tempPtr = tempPtr->getNext();
        if(tempPtr == nullptr) {
            boolL = false;
        } else {
            count++;
        }
    }
    return count;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    return getCurrentSize340RecursiveHelper(headPtr);
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    static Node<ItemType>* nodePtr{ headPtr };
    if (nodePtr != nullptr) {
        nodePtr = nodePtr->getNext();
        return getCurrentSize340RecursiveNoHelper() + 1;
    }
    return 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& entry) const {
    return getFrequencyOf340RecursiveHelper(headPtr, entry);
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& entry) const {
    static Node<ItemType>* nodePtr{ headPtr };
    if (nodePtr != nullptr) {
        if (nodePtr->getItem() == entry) {
            nodePtr = nodePtr->getNext();
            return getFrequencyOf340RecursiveNoHelper(entry) + 1;
        }
        nodePtr = nodePtr->getNext();
        return getFrequencyOf340RecursiveNoHelper(entry);
    }
    nodePtr = headPtr;
    return 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* nodePtr) const {
    if (nodePtr != nullptr) {
        return getCurrentSize340RecursiveHelper(nodePtr->getNext()) + 1;
    }
    return 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* nodePtr, const ItemType& entry) const {
    if (nodePtr != nullptr) {
        if (entry == nodePtr->getItem()) {
            return getFrequencyOf340RecursiveHelper(nodePtr->getNext(), entry) + 1;
        }
        return getFrequencyOf340RecursiveHelper(nodePtr->getNext(), entry);
    }
    return 0;
}

template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
    srand(static_cast<unsigned int>(time(NULL)));
    Node<ItemType>* tempPtr{ headPtr };
    for (int i = 0; i < rand() % itemCount; i++) {
        tempPtr = tempPtr->getNext();
    }
    ItemType tempPtrItem = tempPtr->getItem();
    remove(tempPtr->getItem());
    return tempPtrItem;
}