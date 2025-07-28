#include <iostream>
#include <string>
using namespace std;

class Patient {
protected:
    string name, gender, disease;
    int age;

public:
    void addPatient(string name, int age, string gender, string disease) {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->disease = disease;
    }

    virtual void display() {
        cout << "Patient Name   : " << name << endl;
        cout << "Patient Age    : " << age << endl;
        cout << "Patient Gender : " << gender << endl;
        cout << "Patient Disease: " << disease << endl;
    }

    string getName() { return name; }
};

class Room : public Patient {
protected:
    bool isBooked = false;
    string roomType;
    int days;

public:
    void bookRoom(string roomType, int days) {
        this->roomType = roomType;
        this->days = days;
        isBooked = true;
        cout << "Room booked: " << roomType << " for " << days << " days." << endl;
    }

    void checkRoomStatus() {
        if (isBooked) {
            cout << "The room is currently unavailable." << endl;
        } else {
            cout << "The room is currently available." << endl;
        }
    }

    int getDays() { return days; }
};

class Bill : public Room {
protected:
    int totalBill = 0;

public:
    void generateBill() {
        totalBill = 1100 * days;
        cout << "Your total bill is: ₹" << totalBill << endl;
    }
};

class Hospital : public Bill {
public:
    void bookAppointment() {
        cout << "Your appointment is confirmed." << endl;
    }

    void cancelAppointment() {
        cout << "Your appointment is canceled successfully." << endl;
    }
};

int main() {
    Hospital h;

    h.addPatient("Kapil", 18, "Male", "Flu");
    h.display();
    h.bookAppointment();
    h.checkRoomStatus();
    h.bookRoom("ICU", 10);
    h.generateBill();
    h.cancelAppointment();

    return 0;
}
