//
// Created by aes on 1/10/20.
//

#include <iostream>

class theParent {
public:
    virtual void foo() = 0;
};

class theChild : public theParent
{
public:
    void foo()
    {
    }
    int childOwned;
    theChild()
    {
        childOwned = 4;
    }
};


int main() {
    theParent* nastyPointer = new theChild;
    //theChild * fancyPointer = dynamic_cast<theChild*>(nastyPointer);
    //std::cout << nastyPointer->childOwned << std::endl;
    std::cout << dynamic_cast<theChild*>(nastyPointer)->childOwned << std::endl;
}