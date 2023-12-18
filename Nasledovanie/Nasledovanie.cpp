#include <iostream>
#include <vector>
#include <string>

class Vehicle {
public:
    Vehicle(std::string name, std::string model) : name(name), model(model) {}
    void display() const {
        std::cout << "Vehicle: " << name << " " << model << std::endl;
    }

private:
    std::string name;
    std::string model;
};

class Employee {
public:
    Employee(std::string name, int age, std::string gender, bool married = false, int children = 0)
        : name(name), age(age), gender(gender), married(married), children(children), vehicle(nullptr) {}

    void assignVehicle(Vehicle* newVehicle) {
        vehicle = newVehicle;
    }

    void display() const {
        std::cout << "Employee: " << name << ", Age: " << age << ", Gender: " << gender;
        if (married) {
            std::cout << ", Marital Status: Married, Children: " << children;
        }
        if (vehicle) {
            std::cout << ", Assigned Vehicle: ";
            vehicle->display();
        }
        std::cout << std::endl;
    }

private:
    std::string name;
    int age;
    std::string gender;
    bool married;
    int children;
    Vehicle* vehicle;
};

class Company {
public:
    Company(std::string name, std::string location) : name(name), location(location) {}

    void addEmployee(const Employee& employee) {
        employees.push_back(employee);
    }

    void display() const {
        std::cout << "Company: " << name << ", Location: " << location << std::endl;
        std::cout << "Employees:\n";
        for (const auto& employee : employees) {
            employee.display();
        }
    }

private:
    std::string name;
    std::string location;
    std::vector<Employee> employees;
};

class Truck : public Vehicle {
public:
    Truck(std::string name, std::string model, int capacity)
        : Vehicle(name, model), capacity(capacity) {}

    void display() const {
        Vehicle::display();
        std::cout << "Capacity: " << capacity << " kg " << std::endl;
    }

private:
    int capacity;
};

class Car : public Vehicle {
public:
    Car(std::string name, std::string model, int hp) : Vehicle(name, model), hp(hp) {}

    void display() const {
        Vehicle::display();
        std::cout << "Horsepower: " << hp << std::endl;
    }

private:
    int hp;
};

int main() {
    Company company("World Access", "Krasnodar");
    Employee employee1("Alexandr", 30, "Male", true, 2);
    Employee employee2("Ann", 25, "Female", true, 1);

    Truck truck("GAZ", "3302", 750);
    Car car("Toyota", "Mark II", 280);

    employee1.assignVehicle(&truck);
    employee2.assignVehicle(&car);

    company.addEmployee(employee1);
    company.addEmployee(employee2);

    company.display();

    return 0;
}
