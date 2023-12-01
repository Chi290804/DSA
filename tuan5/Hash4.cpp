#include <bits/stdc++.h>
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
    string s;
    
    while (cin >> s) {
        if (s.substr(0,6) == "Insert") {
            int id;
            char name[100], class_name[100] ;
            sscanf(s.c_str(), "Insert(%d,%[^,],%[^)])", &id, &name[0], &class_name[0]);
            
            manager.insert(id, name, class_name);
        } else if (s.find("Delete") == 0) {
            int id;
            sscanf(s.c_str(), "Delete(%d)", &id);
            manager.erase(id);
        } else if (s.find("Infor") == 0) {
            int id;
            sscanf(s.c_str(), "Infor(%d)", &id);
            string result = manager.info(id);
            cout << result << endl;
        } else {
            break;
        }
    }

    return 0;
}