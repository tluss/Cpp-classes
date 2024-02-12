#include <iostream>
#include <string>

class Plant {
protected:
    int age;
    double height;
    double environment;

public:
    Plant()
        : age(0), height(0.0), environment(0.0) {
    }

    Plant(int initialAge, double initialHeight, double initialEnvironment)
        : age(initialAge), height(initialHeight), environment(initialEnvironment) {
    }

    ~Plant() {
        std::cout << "The plant has decayed.\n";
    }

    int getAge() const {
        return age;
    }

    double getHeight() const {
        return height;
    }

    double getEnvironment() const {
        return environment;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    void setHeight(double newHeight) {
        height = newHeight;
    }

    void setEnvironment(double newEnvironment) {
        environment = newEnvironment;
    }

    virtual void grow() {
        age++;
        height += 0.5;
        environment += 1.0;
    }

    virtual void displayInfo() const {
        std::cout << "Plant Information:\n";
        std::cout << "Age: " << age << " years\n";
        std::cout << "Height: " << height << " units\n";
        std::cout << "Environment: " << environment << " units\n";
    }
};

class Tree : public Plant {
private:
    bool evergreen;

public:
    Tree()
        : Plant(), evergreen(false) {
    }

    Tree(int initialAge, double initialHeight, double initialEnvironment, bool isEvergreen)
        : Plant(initialAge, initialHeight, initialEnvironment), evergreen(isEvergreen) {
    }

    ~Tree() {
        std::cout << "The tree has decayed.\n";
    }

    void shedLeaves() {
        if (evergreen) {
            std::cout << "This evergreen tree doesn't shed leaves.\n";
        } else {
            std::cout << "Leaves are shedding from the deciduous tree.\n";
        }
    }

    void grow() override {
        age++;
        height += 1.0;
        environment += 2.0;
    }

    void displayInfo() const override {
        std::cout << "Tree Information:\n";
        std::cout << "Age: " << age << " years\n";
        std::cout << "Height: " << height << " units\n";
        std::cout << "Environment: " << environment << " units\n";
        std::cout << "Evergreen: " << (evergreen ? "Yes" : "No") << "\n";
    }
};

class Bush : public Plant {
private:
    int numBranches;

public:
    Bush(int initialAge, double initialHeight, double initialEnvironment, int initialBranches)
        : Plant(initialAge, initialHeight, initialEnvironment), numBranches(initialBranches) {
    }

    ~Bush() {
        std::cout << "The bush has decayed.\n";
    }

    void growBerries() {
        std::cout << "The bush is growing berries.\n";
    }

    void grow() override {
        age++;
        height += 0.8;
        environment += 1.5;
    }

    void displayInfo() const override {
        std::cout << "Bush Information:\n";
        std::cout << "Age: " << age << " years\n";
        std::cout << "Height: " << height << " units\n";
        std::cout << "Environment: " << environment << " units\n";
        std::cout << "Number of Branches: " << numBranches << "\n";
    }
};

class Flower : public Plant {
private:
    std::string color;

public:
    Flower(int initialAge, double initialHeight, double initialEnvironment, const std::string& initialColor)
        : Plant(initialAge, initialHeight, initialEnvironment), color(initialColor) {
    }

    ~Flower() {
        std::cout << "The flower has decayed.\n";
    }

    void bloom() {
        std::cout << "The flower is blooming in beautiful " << color << " color.\n";
    }

    void grow() override {
        age++;
        height += 0.3;
        environment += 0.8;
    }

    void displayInfo() const override {
        std::cout << "Flower Information:\n";
        std::cout << "Age: " << age << " years\n";
        std::cout << "Height: " << height << " units\n";
        std::cout << "Environment: " << environment << " units\n";
        std::cout << "Color: " << color << "\n";
    }
};

class Crop : public Plant {
private:
    std::string cropType;

public:
    Crop(int initialAge, double initialHeight, double initialEnvironment, const std::string& initialType)
        : Plant(initialAge, initialHeight, initialEnvironment), cropType(initialType) {
    }

    ~Crop() {
        std::cout << "The crop has decayed.\n";
    }

    void harvest() {
        std::cout << "Harvesting the " << cropType << " crop.\n";
    }

    void grow() override {
        age++;
        height += 0.7;
        environment += 1.2;
    }

    void displayInfo() const override {
        std::cout << "Crop Information:\n";
        std::cout << "Age: " << age << " years\n";
        std::cout << "Height: " << height << " units\n";
        std::cout << "Environment: " << environment << " units\n";
        std::cout << "Crop Type: " << cropType << "\n";
    }
};

int main() {
    Tree myTree(5, 8.0, 20.0, true);
    Bush myBush(3, 2.5, 15.0, 5);
    Flower myFlower(1, 0.5, 2.0, "Red");
    Crop myCrop(2, 1.2, 8.0, "Wheat");

    myTree.displayInfo();
    myTree.grow();
    myTree.shedLeaves();
    myTree.displayInfo();

    myBush.displayInfo();
    myBush.grow();
    myBush.growBerries();
    myBush.displayInfo();

    myFlower.displayInfo();
    myFlower.grow();
    myFlower.bloom();
    myFlower.displayInfo();

    myCrop.displayInfo();
    myCrop.grow();
    myCrop.harvest();
    myCrop.displayInfo();
    
    return 0;
}