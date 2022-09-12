//	LinkedBag340.cpp
//	Created by: 340


#include <iostream>
#include <ctime>
#include "Node.h"
#include "LinkedBag.h"

template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {

    shared_ptr<Node<ItemType>> getSecondNode = headPtr->getNext(); //gets the pointer to second node
    shared_ptr<Node<ItemType>> getThirdNode = getSecondNode->getNext(); //gets the pointer to the third node
    headPtr->setNext(getThirdNode); //here we set head to third node and skipping second node
     // Below I borrowed the code from linkedBag we remove second node, remove method is written in Linkedbag

    shared_ptr<Node<ItemType>> entryNodePtr{getPointerTo(getSecondNode->getItem())};
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);

    if (canRemoveItem) {
        entryNodePtr->setItem(headPtr->getItem());

        shared_ptr<Node<ItemType>> nodeToDeletePtr{ headPtr };
        headPtr = headPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);



        itemCount--;
    }
    return canRemoveItem;
}

template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry) {
    unique_ptr<Node<ItemType>> uniqueNodePtr = make_unique<Node<ItemType>>();
    uniqueNodePtr->setItem(newEntry);
    uniqueNodePtr->setNext(nullptr);
    shared_ptr<Node<ItemType>> sharedNodePtr = headPtr;
    if(headPtr==nullptr)
    {
        headPtr = move(uniqueNodePtr);
        return 0;
    }
    while (sharedNodePtr->getNext() != nullptr)
    {
        sharedNodePtr = sharedNodePtr->getNext();
    }
    sharedNodePtr->setNext(move(uniqueNodePtr));
    itemCount++;
    return true;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    if (headPtr == nullptr) {
        return 0;
    }
    // Node<ItemType>* tempPtr{ headPtr };
    shared_ptr<Node<ItemType>> tempPtr{ headPtr };
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

// let's try to use weak_ptr for recursive looping
//int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
//
//    if (headPtr == nullptr) {
//  //      cout << "retrurned zero 0:" << endl;
//        return 0;
//    }
//
//    // Node<ItemType>* sharedNodePtr{ headPtr };
//    shared_ptr<Node<ItemType>> sharedNodePtr{make_shared<Node<ItemType>>(headPtr) };
//    weak_ptr<Node<ItemType>> weakTempPtr{sharedNodePtr };
//    weakTempPtr = sharedNodePtr;
//    int count = 1;
//    bool loopB = true;
//    while (loopB) {
//        if (!weakTempPtr.expired()) {
//
//
//            shared_ptr<Node<ItemType>> tempTempPtr{weakTempPtr.lock()};
//            if (tempTempPtr) {
//                // tempTemp is not empty
//           //    weak_ptr<Node<ItemType>> weakTempPtr = weakTempPtr
//            } else {
//                break;
//            }
//              p = weakTempPtr.lock();
//            // cout << "pPp" << p << endl;
//
//            //     weakTempPtr.use_count();
//            //    cout << "weakTempPtr.use_count();" << weakTempPtr.use_count() << endl;
//            if (sharedNodePtr == nullptr) {
//                loopB = false;
//                break;
//            }
//            weakTempPtr.reset();
//            count++;
//       //     weakTempPtr.reset()
//        }
//    }
//
//  //
//    return count;
//} COULD NOT IMPLEMENT WITHOUT AUTO for weak_ptr

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    return getCurrentSize340RecursiveHelper(headPtr);
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    // static Node<ItemType>* sharedNodePtr{ headPtr };
    static shared_ptr<Node<ItemType>> sharedNodePtr{headPtr };
    if (sharedNodePtr != nullptr) {
        sharedNodePtr = sharedNodePtr->getNext();
        return getCurrentSize340RecursiveNoHelper() + 1;
    }
    sharedNodePtr = headPtr;
    return 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& entry) const {
    return getFrequencyOf340RecursiveHelper(headPtr, entry);
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& entry) const {
    // static Node<ItemType>* sharedNodePtr{ headPtr };
    static shared_ptr<Node<ItemType>> sharedNodePtr{headPtr };
    if (sharedNodePtr != nullptr) {
        if (sharedNodePtr->getItem() == entry) {
            sharedNodePtr = sharedNodePtr->getNext();
            return getFrequencyOf340RecursiveNoHelper(entry) + 1;
        }
        sharedNodePtr = sharedNodePtr->getNext();
        return getFrequencyOf340RecursiveNoHelper(entry);
    }
    sharedNodePtr = headPtr;
    return 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(shared_ptr<Node<ItemType>> sharedNodePtr) const {
    if (sharedNodePtr != nullptr) {
        return getCurrentSize340RecursiveHelper(sharedNodePtr->getNext()) + 1;
    }
    return 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(shared_ptr<Node<ItemType>> sharedNodePtr, const ItemType& entry) const {
    if (sharedNodePtr != nullptr) {
        if (entry == sharedNodePtr->getItem()) {
            return getFrequencyOf340RecursiveHelper(sharedNodePtr->getNext(), entry) + 1;
        }
        return getFrequencyOf340RecursiveHelper(sharedNodePtr->getNext(), entry);
    }
    return 0;
}

template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
    srand(static_cast<unsigned int>(time(0)));

    shared_ptr<Node<ItemType>> tempPtr{ headPtr };
    for (int i = 0; i < rand() % itemCount; i++) {
        tempPtr = tempPtr->getNext();
    }
    ItemType tempPtrItem = tempPtr->getItem();
    remove(tempPtr->getItem());
    return tempPtrItem;
}