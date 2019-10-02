/**
 * 
 * The Linked List Implementation Code
 * 
 * Copyright (c) Alex4386. Distributed under HRPL
 * 
 **/

#include <stdlib.h>
#include "linkedList.h"

/**
 * Node Constructor
 * 
 * @params key the key to goes inside of node
 **/
Node *constructNode(int key) {
    Node* node = (Node *)malloc(sizeof(Node));

    // initialize node
    node->key = key;
    node->nextPtr = NULL;

    return node;
}

/**
 * check whether next Node Exists
 * 
 * @params node: node to check
 * @return 0 when doesn't exist or invalid input. 1 when nextNode exists.
 **/
char nextNodeExist(Node *node) {
    // validate node is real
    if (node == NULL) {
        return 0;
    }

    if (node->nextPtr == NULL) {
        return 0;
    }

    return 1;
}

/**
 * add next node
 * 
 * @params baseNode the node to add next node
 * @params key the key for new node
 * @returns Node pointer of new node
 **/
Node *addNextNode(Node *baseNode, int key) {
    Node* nextNode = constructNode(key);
    if (nextNodeExist(baseNode)) {
        nextNode->nextPtr = baseNode->nextPtr;
    }
    baseNode->nextPtr = nextNode;

    return nextNode;
}

/**
 * get Previous Node
 * 
 * @params baseNode the node to add next node
 * @params key the key for new node
 * @returns Node pointer of new node
 **/
Node *getPreviousNode(Node *baseNode, Node *node) {
    if (node == NULL || baseNode == NULL) {
        return NULL;
    }
    
    Node *findingNode = baseNode;

    while (1) {
        findingNode = baseNode->nextPtr;
        if (findingNode->nextPtr == node) {
            return findingNode;
        }
        if (!nextNodeExist(findingNode)) {
            break;
        }
        findingNode = getNextNode(findingNode);
    }

    return NULL;
}

/**
 * get Next Node: synonym of node->nextPtr
 **/ 
Node *getNextNode(Node *node) {
    return node->nextPtr;
}

/**
 * get how many next nodes are available
 * 
 * @params count how many next nodes
 * @return nodes next count you specified, if it is unable, last Node pointer will be returned.
 **/
Node *getNextCountNode(Node *node, int count) {
    Node *countNode = node;
    for (int i = 0; i < count && nextNodeExist(node); i++) {
        countNode = getNextNode(countNode);
    }
    return countNode;
}

/**
 * get how many nodes away from the specific node
 * 
 * @params baseNode the node to check the distance
 * @return returns how many indexes away, if it is not found, function returns -1.
 **/
int getCurrentNodeIndex(Node *baseNode, Node *node) {
    Node *countNode = baseNode;
    int index = 0;
    while (1) {
        if (countNode == node) {
            return index;
        }
        if (!nextNodeExist(countNode)) {
            break;
        }
        countNode = getNextNode(countNode);
        index++;
    }

    return -1;
}

/**
 * find a first-occuring node via key of the node.
 * 
 * @params baseNode the node to find the node
 * @return returns Node Pointer if it is found, e.
 **/
Node *findByKey(Node *baseNode, int key) {
    Node *findingNode = baseNode;
    while (1) {
        if (findingNode->key == key) {
            return findingNode;
        }
        if (!nextNodeExist(findingNode)) {
            break;
        }
        findingNode = getNextNode(findingNode);
    }

    return NULL;
}

