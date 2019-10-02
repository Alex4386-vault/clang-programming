/**
 * 
 * The Linked List Implementation Header
 * 
 * Copyright (c) Alex4386. Distributed under HRPL
 * 
 **/

/**
 * The Node itself
 **/
typedef struct Node {
    int key;
    struct Node *nextPtr;
} Node;

/**
 * Node Constructor
 * 
 * @params key the key to goes inside of node
 **/
Node *constructNode(int key);

/**
 * check whether next Node Exists
 * 
 * @params node: node to check
 * @return 0 when doesn't exist or invalid input. 1 when nextNode exists.
 **/
char nextNodeExist(Node *node);

/**
 * add next node
 * 
 * @params baseNode the node to add next node
 * @params key the key for new node
 * @returns Node pointer of new node
 **/
Node *addNextNode(Node *baseNode, int key);

/**
 * get Previous Node
 * 
 * @params baseNode the node to add next node
 * @params key the key for new node
 * @returns Node pointer of new node
 **/
Node *getPreviousNode(Node *baseNode, Node *node);

/**
 * get Next Node: synonym of node->nextPtr
 **/ 
Node *getNextNode(Node *node);

/**
 * get how many next nodes are available
 * 
 * @params count how many next nodes
 * @return nodes next count you specified, if it is unable, last Node pointer will be returned.
 **/
Node *getNextCountNode(Node *node, int count);

/**
 * get how many nodes away from the specific node
 * 
 * @params baseNode the node to check the distance
 * @return returns how many indexes away, if it is not found, function returns -1.
 **/
int getCurrentNodeIndex(Node *baseNode, Node *node);

/**
 * find a first-occuring node via key of the node.
 * 
 * @params baseNode the node to find the node
 * @return returns Node Pointer if it is found, e.
 **/
Node *findByKey(Node *baseNode, int key);
