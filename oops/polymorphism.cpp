//! Polymorphism Theory:
//! 1. Ability of objects to take multiple forms
//! 2. Types: Compile-time (Method Overloading) and Runtime (Method Overriding)
//! 3. Virtual functions enable runtime polymorphism
//! 4. Base class pointer can point to derived class objects
//! 5. Helps achieve code reusability and flexibility

#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
    
    virtual float area() {
        return 0;
    }
};

// Derived class 1
class Circle : public Shape {
private:
    float radius;
    
public:
    Circle(float r) : radius(r) {}
    
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
    
    float area() override {
        return 3.14159 * radius * radius;
    }
};

// Derived class 2
class Rectangle : public Shape {
private:
    float width;
    float height;
    
public:
    Rectangle(float w, float h) : width(w), height(h) {}
    
    void draw() override {
        cout << "Drawing a rectangle" << endl;
    }
    
    float area() override {
        return width * height;
    }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Shape();
    shapes[1] = new Circle(5);
    shapes[2] = new Rectangle(4, 6);
    
    // Runtime polymorphism
    for(int i = 0; i < 3; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->area() << endl;
    }
    
    // Clean up
    for(int i = 0; i < 3; i++) {
        delete shapes[i];
    }
    
    return 0;
}
