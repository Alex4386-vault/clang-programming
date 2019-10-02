#include <stdio.h>
#include "linkedList.h"

int main() {
    Node *baseNode = constructNode(10);
    addNextNode(baseNode, 20);
    addNextNode(baseNode, 30);

    Node *node = baseNode;
    while (1) {
        printf("%d\n", node->key);
        if (!nextNodeExist(node)) {
            break;
        }
        node = getNextNode(node);
    }

    return 0;
}