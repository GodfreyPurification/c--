#include <iostream>
#include <string>
#include <vector>
#include <windows.h>  // Required for MessageBox function

using namespace std;

class MyVehiclesClass {
public:
    string brand;
    string model;
    int milage;
    int yearModel;
};

int main() {
    string msg;  // Variable to hold the concatenated message
    vector<string> message;  // Vector to hold individual details
    MyVehiclesClass MyVehicleObject1;

    // Input vehicle details
    cout << "Car Brand: ";
    getline(cin, MyVehicleObject1.brand);

    cout << "Car Model: ";
    getline(cin, MyVehicleObject1.model);

    cout << "Car Milage: ";
    cin >> MyVehicleObject1.milage;
    // cin.ignore();  // Clear the newline character left in the buffer after reading milage

    cout << "Car Model Year: ";
    cin >> MyVehicleObject1.yearModel;
    // cin.ignore();  // Clear the newline character after yearModel

    // Store car details in a vector of strings
    message.push_back("Car Details:");
    message.push_back("Car Brand: " + MyVehicleObject1.brand);
    message.push_back("Car Model: " + MyVehicleObject1.model);
    message.push_back("Car Milage: " + to_string(MyVehicleObject1.milage));
    message.push_back("Car Year Model: " + to_string(MyVehicleObject1.yearModel));

    // Concatenate all messages into one single string
    for (const string& issue : message) {
        msg += issue + " ";  // Adding newline for better formatting
    }

    // Construct the command to open cmd and display the message
    string command = "start cmd /K \"echo " + msg + " && pause && exit\"";

    // Use system() to execute the command that opens the new window and shows the message
    system(command.c_str());

    return 0;
}
