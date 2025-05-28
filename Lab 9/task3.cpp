#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<numeric>
using namespace std;

class Employee {
    public:
    int empId;
    string name;
    string dep;
    double salary;

    Employee(int id, string n, string d, double s): empId(id), name(n), dep(d), salary(s) {}
    void display(){
        cout << "ID: " << empId
             << " | Name: " << name
             << " | Department: " << dep
             << " | Salary: " << salary << endl;
    }
};

class EmployeeManager {
    public:
    map<int,Employee> employeeRecord;
    vector<Employee> employees;

    void addEmployee(Employee e){
        employeeRecord.insert({e.empId, e});
        employees.push_back(e);
    }
    void deleteEmployee(int id){
        employeeRecord.erase(id);
    }
    void displayAll(){
        cout<<"All Employees: "<<endl;
        for(auto& n : employeeRecord){
            n.second.display();
        }
    }
    struct Ascend{
        bool operator()(Employee e1, Employee e2){
            return e1.salary<e2.salary;
        }
    };
    void sortBySalary(){
        vector<Employee> emp = employees;
        sort(emp.begin(), emp.end(), Ascend());
        cout<<"Sorted by Salary: "<<endl;
        for(auto n: emp){
            n.display();
        }
    }
    void sortByName(){
        vector<Employee> emp = employees;
        sort(emp.begin(), emp.end(), 
        [](Employee e1, Employee e2){
            return e1.name < e2.name;
        }
    );
        for(auto n: emp){
            n.display();
        }
    }

    double calcAvg(){
        double total = 0;
        for(auto& n : employeeRecord){
            total += n.second.salary;
        }
        return total/employeeRecord.size();
    }

    void filterBySalary(double threshold) const {
        vector<Employee> r;
        copy_if(employees.begin(), employees.end(), back_inserter(r),
    [threshold](Employee e){
        return e.salary > threshold;
    }
    );
    for(Employee e : r){
        e.display();
    }
    }

    static bool Descend(Employee e1, Employee e2){
        return e1.salary > e2.salary;
    }
    void sortSalaryDescend(){
        vector<Employee> emp = employees;
        sort(emp.begin(), emp.end(), Descend);
        cout<<"Sorted by Salary in descending order: "<<endl;
        for(auto n: emp){
            n.display();
        }
    }
    void customDisplay(void (*func)(Employee e)){
        for(auto n: employeeRecord){
            func(n.second);
        }
    }
};

void displayIdAndName(Employee e){
    cout<<"ID : "<<e.empId<<" | Name: "<<e.name<<endl;
}

int main() {
    Employee e1(1,"Ayyan","CS", 100);
    Employee e2(2, "Basim", "Med" , 30);
    Employee e3(3, "Arwaa", "BBA", 51);
    EmployeeManager manager;
    manager.addEmployee(e1);
    manager.addEmployee(e2);
    manager.addEmployee(e3);
    manager.displayAll();
    manager.filterBySalary(50);
    manager.sortBySalary();
    manager.sortSalaryDescend();
    manager.sortByName();
    manager.customDisplay(displayIdAndName);
    double avg = manager.calcAvg();
    cout<<avg<<endl;
    manager.deleteEmployee(2);
    manager.displayAll();
    manager.filterBySalary(50);
    manager.sortBySalary();
    manager.sortSalaryDescend();
    manager.sortByName();
    manager.sortByName();
    manager.customDisplay(displayIdAndName);
    cout<<avg<<endl;

    return 0;

}