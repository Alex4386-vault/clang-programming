#include <iostream>

class Calc {
    public:
        int a;
        int b;

        int add() {
            return this->a+this->b;
        }
        int minus() {
            return this->a-this->b;
        }
        int multiply() {
            return this->a*this->b;
        }
        int divide() {
            return this->a/this->b;
        }
        int remainder() {
            return this->a%this->b;
        }
};

int main() {
    Calc calc;
    calc.a = 10;
    calc.b = 2;

    std::cout << calc.add() << std::endl;
    std::cout << calc.minus() << std::endl;
    std::cout << calc.multiply() << std::endl;
    std::cout << calc.divide() << std::endl;
    std::cout << calc.remainder() << std::endl;
}