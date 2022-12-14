//  LinkedBag.cpp
//  Created by Frank M. Carrano and Timothy M. Henry.
//	Updated by Duc Ta
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <cstddef>
#include "Node.h"
#include "LinkedBag.h"

//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//

template<typename ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0) {}

template<typename ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag) {
    itemCount = aBag.itemCount;
    //Node<ItemType>* origChainPtr = aBag.headPtr;
    shared_ptr<Node<ItemType>> origChainPtr{ aBag.headPtr };

    if (origChainPtr == nullptr) {
        headPtr = nullptr;
    }
    else {
        // headPtr = new Node<ItemType>();
        // headPtr->setItem(origChainPtr->getItem());
        headPtr = make_shared<Node<ItemType>>(origChainPtr->getItem());

        // Node<ItemType>* newChainPtr = headPtr;
        shared_ptr<Node<ItemType>> newChainPtr = headPtr;
        origChainPtr = origChainPtr->getNext();

        while (origChainPtr != nullptr)
        {
            ItemType nextItem = origChainPtr->getItem();
            // Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            shared_ptr<Node<ItemType>> newNodePtr{ make_shared<Node<ItemType>>(nextItem) };
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }

        newChainPtr->setNext(nullptr);
    }
}

template<typename ItemType>
LinkedBag<ItemType>::~LinkedBag() {
    cout << " '~Destructor called on' " << endl;
}

template<typename ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
    return itemCount;
}

template<typename ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry) {
//     Node<ItemType>* nextNodePtr = new Node<ItemType>();
//     nextNodePtr->setItem(newEntry);
//     nextNodePtr->setNext(headPtr);
    shared_ptr<Node<ItemType>> nextNodePtr{ make_shared<Node<ItemType>>(newEntry, headPtr) };
    headPtr = nextNodePtr;
    itemCount++;
    return true;
}

template<typename ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const {
    std::vector<ItemType> bagContents;
    // Node<ItemType>* curPtr = headPtr;
    shared_ptr<Node<ItemType>> curPtr{ headPtr };
    int counter = 0;

    while ((curPtr != nullptr) && (counter < itemCount)) {
        bagContents.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
        counter++;
    }

    return bagContents;
}

template<typename ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry) {
    // Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
    shared_ptr<Node<ItemType>> entryNodePtr{getPointerTo(anEntry)};
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);

    if (canRemoveItem) {
        entryNodePtr->setItem(headPtr->getItem());
        // Node<ItemType>* nodeToDeletePtr = headPtr;
        shared_ptr<Node<ItemType>> nodeToDeletePtr{ headPtr };
        headPtr = headPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);
        // delete nodeToDeletePtr;								// removes requirement to delete object
        // nodeToDeletePtr = nullptr;							// and to set pointer to null

        itemCount--;
    }

    return canRemoveItem;
}

template<typename ItemType>
void LinkedBag<ItemType>::clear() {
    /* Node<ItemType>* nodeToDeletePtr = headPtr;

    while (headPtr != nullptr) {
        headPtr = headPtr->getNext();
        nodeToDeletePtr->setNext(nullptr);
        nodeToDeletePtr.reset();
        nodeToDeletePtr = headPtr;
    }
    */
    headPtr.reset();
    itemCount = 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
    int frequency = 0;
    int counter = 0;

    shared_ptr<Node<ItemType>> curPtr{ headPtr };

    while ((curPtr != nullptr) && (counter < itemCount)) {
        if (anEntry == curPtr->getItem()) {
            frequency++;
        }
        counter++;
        curPtr = curPtr->getNext();
    }

    return frequency;
}

template<typename ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const {
    return (getPointerTo(anEntry) != nullptr);
}

template<typename ItemType>

shared_ptr<Node<ItemType>> LinkedBag<ItemType>::getPointerTo(const ItemType & anEntry) const {
    bool found = false;
    shared_ptr<Node<ItemType>> curPtr = headPtr;

    while (!found && (curPtr != nullptr)) {
        if (anEntry == curPtr->getItem()) {
            found = true;
        }
        else {
            curPtr = curPtr->getNext();
        }
    }

    return curPtr;
} 