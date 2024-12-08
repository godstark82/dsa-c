//! Abstraction Theory:
//! 1. Hiding complex implementation details and showing only necessary features
//! 2. Achieved through abstract classes and interfaces
//! 3. Abstract classes have at least one pure virtual function
//! 4. Cannot create objects of abstract classes
//! 5. Derived classes must implement all pure virtual functions
//! 6. Helps manage complexity and provides implementation hiding

#include <iostream>
using namespace std;

class InstaRepo
{
public:
    virtual void getAllPosts();
    virtual void getPostById();
    virtual int getFollowerCount();
};

class InstaRepoImplementation : public InstaRepo
{
public:
    void getAllPosts()
    {
        cout << "All Posts" << endl;
    }
    void getPostById()
    {
        cout << "Post By ID: " << endl;
    }

    int getFollowerCount()
    {
        return 100;
    }
};

int main(){
    InstaRepoImplementation repo;
    repo.getAllPosts();
}