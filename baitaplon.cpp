#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BaseEntity {
public:
    virtual void display() = 0;
    virtual void add() = 0;
    virtual void remove() = 0;
    virtual void update() = 0;
    virtual ~BaseEntity() {}
};

class ClassRoom : public BaseEntity {
private:
    struct ClassInfo {
        string id, name, major, type;
    };
    vector<ClassInfo> classes;

public:
    void display() override {
        cout << "\n===== DANH SACH LOP HOC =====\n";
        if (classes.empty()) { cout << "Chua co lop nao\n"; return; }
        for (auto &c : classes) {
            cout << "Ma lop: " << c.id
                << " | Ten: " << c.name
                << " | Chuyen nganh: " << c.major
                << " | Loai: " << c.type << endl;
        }
    }

    void add() override {
        ClassInfo c;
        cout << "\nNhap ma lop: "; getline(cin, c.id);
        cout << "Nhap ten lop: "; getline(cin, c.name);
        cout << "Nhap chuyen nganh: "; getline(cin, c.major);
        cout << "Nhap loai lop (CNTT/NN): "; getline(cin, c.type);
        classes.push_back(c);
        cout << "=> Them lop thanh cong!\n";
    }

    void remove() override {
        string id;
        cout << "\nNhap ma lop can xoa: ";
        getline(cin, id);
        for (auto it = classes.begin(); it != classes.end(); ++it) {
            if (it->id == id) {
                classes.erase(it);
                cout << "=> Xoa thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay lop!\n";
    }

    void update() override {
        string id;
        cout << "\nNhap ma lop can cap nhat: ";
        getline(cin, id);
        for (auto &c : classes) {
            if (c.id == id) {
                cout << "Nhap ten lop moi: "; getline(cin, c.name);
                cout << "Nhap chuyen nganh moi: "; getline(cin, c.major);
                cout << "Nhap loai moi: "; getline(cin, c.type);
                cout << "=> Cap nhat thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay lop!\n";
    }
};

class Student : public BaseEntity {
private:
    struct StudentInfo {
        string id, name, dob, email, phone;
    };
    vector<StudentInfo> students;

public:
    void display() override {
        cout << "\n===== DANH SACH SINH VIEN =====\n";
        if (students.empty()) { cout << "Chua co sinh vien\n"; return; }
        for (auto &s : students) {
            cout << "Ma SV: " << s.id
                << " | Ten: " << s.name
                << " | Ngay sinh: " << s.dob
                << " | Email: " << s.email
                << " | SDT: " << s.phone << endl;
        }
    }

    void add() override {
        StudentInfo s;
        cout << "\nNhap ma sinh vien: "; getline(cin, s.id);
        cout << "Nhap ten sinh vien: "; getline(cin, s.name);
        cout << "Nhap ngay sinh: "; getline(cin, s.dob);
        cout << "Nhap email: "; getline(cin, s.email);
        cout << "Nhap so dien thoai: "; getline(cin, s.phone);
        students.push_back(s);
        cout << "=> Them sinh vien thanh cong!\n";
    }

    void remove() override {
        string id;
        cout << "\nNhap ma sinh vien can xoa: ";
        getline(cin, id);
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "=> Xoa thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay sinh vien!\n";
    }

    void update() override {
        string id;
        cout << "\nNhap ma sinh vien can cap nhat: ";
        getline(cin, id);
        for (auto &s : students) {
            if (s.id == id) {
                cout << "Nhap ten moi: "; getline(cin, s.name);
                cout << "Nhap ngay sinh moi: "; getline(cin, s.dob);
                cout << "Nhap email moi: "; getline(cin, s.email);
                cout << "Nhap SDT moi: "; getline(cin, s.phone);
                cout << "=> Cap nhat thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay sinh vien!\n";
    }
};

void submenu(BaseEntity* entity) {
    int choice;
    do {
        cout << "\n1. Hien thi\n2. Them moi\n3. Xoa\n4. Cap nhat\n0. Quay lai\nChon: ";
        cin >> choice; cin.ignore();
        switch (choice) {
            case 1: entity->display(); break;
            case 2: entity->add(); break;
            case 3: entity->remove(); break;
            case 4: entity->update(); break;
        }
    } while (choice != 0);
}

int main() {
    ClassRoom classMgr;
    Student studentMgr;
    int choice;

    do {
        cout << "\n===== MENU QUAN LY RIKKEI EDU =====\n";
        cout << "1. Quan ly lop hoc\n";
        cout << "2. Quan ly sinh vien\n";
        cout << "0. Thoat\nChon: ";
        cin >> choice; cin.ignore();

        if (choice == 1) submenu(&classMgr);
        else if (choice == 2) submenu(&studentMgr);

    } while (choice != 0);

    return 0;
}
