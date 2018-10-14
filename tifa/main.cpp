#include "main.h"
#include "functions.h"
#include <iostream>
#include <memory>

#include <string>
#include <vector>

class Animal {
private:
    int age;
    //std::string name;
protected:

public:
    int getAge(){
        return age;
    }

    void setAge(int a){
        age = a;
    }

    Animal(){
        std::cout << "Let there be an Animal!" << std::endl;
    }
    Animal(const Animal &a) {
        std::cout << "Original : "<< a.age << std::endl;
        age = a.age + 1;
        std::cout << "Clone : "<< age << std::endl;
        std::cout << "Clone Animal's ass!" << std::endl;
    }
    ~Animal(){
        std::cout << "Age : "<< age << std::endl;
        std::cout << "Reap Animal's soul!" << std::endl;
    }
};

Animal* ex2(Animal* myCat){
    // Animal* myCat = new Animal(); // Ex2
    //equivelant to: (*myCat).setAge(1);
    myCat->setAge(1);
    std::cout << "Cat's age: " << myCat->getAge() << std::endl;
    
    // delete myCat;
    // Even though deleted, memory not yet freed from this process, might still be accessible!! 
    // std::cout << "Cat's age: " << myCat->getAge() << std::endl;    
    
    // This will cause a copy if return value was Animal, not a pointer to Animal
    //return *myCat;
    
    return myCat;
}

bool isAnimalYoung(Animal* a, int young ){
    if (a->getAge() < young){
        std::cout << "Younger, its age: " << a->getAge() << std::endl;
        return true;
    }
    return false;
}

int main(int argc, char** argv){
    nothing(1); // Ex1
    
    std::cout << "Ex2 begin.." << std::endl;
    Animal* myCat = new Animal();
    ex2(myCat);
    std::cout << "Age Check >>> "  << std::endl;
    myCat->setAge(2);
    isAnimalYoung(myCat, 5);

    std::cout << "Ex2 bye.." << std::endl;
    //std::shared_ptr<Animal> a = std::make_shared<Animal>();
    //std::cout << "Hello TIFA!" << std::endl;
    std::cout << "Destroying.." << std::endl;
    delete myCat;
    std::cout << "Destroyed.." << std::endl;

    return 0;
}

