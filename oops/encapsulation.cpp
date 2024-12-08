//! Encapsulation Theory:
//! 1. Bundling of data and methods that operate on that data within a single unit/class
//! 2. Hiding internal details and providing an interface to access the data (data hiding)
//! 3. Access modifiers (public, private, protected) control access to class members
//! 4. Getter/Setter methods provide controlled access to private data
//! 5. Helps achieve data abstraction and data hiding
//! 6. Prevents unauthorized access and maintains data integrity

class Sample {
    private:
        int data;
        string name;
    
    public:
        // Constructor
        Sample(int d, string n) {
            data = d;
            name = n;
        }

        // Getter methods
        int getData() {
            return data;
        }

        string getName() {
            return name;
        }

        // Setter methods 
        void setData(int d) {
            data = d;
        }

        void setName(string n) {
            name = n;
        }
};