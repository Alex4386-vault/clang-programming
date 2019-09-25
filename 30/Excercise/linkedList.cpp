#include <iostream>
#include <vector>

template <class T>
class Block {
    public:
        Block *nextBlock;
        T data;

        Block(T data, Block<T> nextBlock) {
            this->nextBlock = nextBlock;
            this->data = data;
        }

        Block findNext() {
            return *nextBlock;
        }
};

std::vector<Block<int>> ang(10);

// 예전에는 C++이 그렇게 싫었는데 지금은 재밌더라고요?

int main() {
    
}
