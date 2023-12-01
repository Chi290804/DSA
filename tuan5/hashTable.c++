#include <bits/stdc++.h>
using namespace std;
/* 1: 2 desireable properties are: Nhanh, khong trung lap */
#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;
    string className;

    Student(int _id, string _name, string _class) {
        id = _id;
        name = _name;
        className = _class;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void insert(int id, string name, string _class) {
        Student student(id, name, _class);
        students.push_back(student);
    }

    void erase(int id) {
        for (auto it = students.begin(); it != students.end(); it++) {
            if (it->id == id) {
                students.erase(it);
                break;
            }
        }
    }

    string info(int id) {
        for (const auto& student : students) {
            if (student.id == id) {
                return student.name + "," + student.className;
            }
        }
        return "NA,NA";
    }
};

int main() {
    StudentManager manager;

    string operation;
    while (getline(cin, operation)) {
        if (operation.find("Insert") == 0) {
            int id;
            string name, _class;
            sscanf(operation.c_str(), "Insert %d %s %s", &id, name, _class);
            manager.insert(id, name, _class);
        } else if (operation.find("Delete") == 0) {
            int id;
            sscanf(operation.c_str(), "Delete %d", &id);
            manager.erase(id);
        } else if (operation.find("Infor") == 0) {
            int id;
            sscanf(operation.c_str(), "Infor %d", &id);
            string result = manager.info(id);
            cout << result << endl;
        } else {
            break;
        }
    }

    return 0;
}