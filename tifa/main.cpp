#include "main.h"
#include "functions.h"
#include <iostream>
#include <memory>

#include <string>
#include <vector>

class Animal {
private:
    int age;
    std::string name;
protected:
    bool guts;
    Animal(){
        std::cout << "Animal::Animal(): Let there be an Animal!" << std::endl;
    }
public:
    int getAge() const {
        return age;
    }

    void setAge(int a){
        age = a;
    }

    std::string getName() const {
        return name;
    }

    virtual void setName(std::string n){
        name = n;
    }

    

    Animal(const Animal &a) {
        std::cout << "Animal::Animal(Animal&): Original : "<< a.age << std::endl;
        age = a.age + 1;
        std::cout << "      Clone : " << age << std::endl;
        std::cout << "      Clone Animal's ass!" << std::endl;
    }
    virtual ~Animal(){
        std::cout << "Animal::~Animal(): Reap Animal's soul! " << name << ", " << age << std::endl;
    }
};

class Cat final: public Animal {
private:
    int furColor;
public:
    bool hasGuts() const{
        return guts;
    }

    void giveGuts(bool g){
        guts = g;
    }

    int getCatAge()const{
        return Animal::getAge();
    }
    void setAge(int a) {
        Animal::setAge(a*7);
        // age = a*7;
    }

    int getFurColor() const {
        return furColor;
    }

    void setFurColor(int x){
        furColor = x;
    }

    void setName(std::string n) override{
        Animal::setName(n + "Kitty");
    }

    Cat(){
        std::cout << "Cat::Cat()" << std::endl;
    }

    ~Cat(){
        std::cout << "Cat::~Cat()" << std::endl;
    }
};


Animal* ex2SetAge(Animal* myCat){
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
    // nothing(1); // Ex1
    
    // std::cout << "Ex2 begin.." << std::endl;
    // Animal* myCat = new Animal();
    // ex2SetAge(myCat);
    // std::cout << "Age Check >>> "  << std::endl;
    // myCat->setAge(2);
    // isAnimalYoung(myCat, 5);

    // std::cout << "Ex2 bye.." << std::endl;
    // //std::shared_ptr<Animal> a = std::make_shared<Animal>();
    // //std::cout << "Hello TIFA!" << std::endl;
    // std::cout << "Destroying.." << std::endl;
    // delete myCat;
    // std::cout << "Destroyed.." << std::endl;

    std::cout << "-----------------------------" << std::endl;
    Cat* otta = new Cat();
    //myAnimal->guts = true;
    otta->setAge(18);
    std::cout << "Age: ";
    std::cout << otta->getAge() << std::endl;
    otta->setFurColor(20) ;
    std::cout << "Fur: ";
    std::cout << otta->getFurColor() << std::endl;
    delete otta;
    std::cout << "-----------------------------" << std::endl;

    Animal* anonymousAnimal = new Cat();
    ((Cat*)anonymousAnimal)->setAge(2);
    delete (Cat*)anonymousAnimal;

    std::cout << "-----------------------------" << std::endl;
    Animal* adoptedAnimal = new Cat();
    adoptedAnimal->setName("Viima");
    delete adoptedAnimal;

    return 0;
}

