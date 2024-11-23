#include <iostream>
#include <string>
#include <vector>
using namespace std;
string Global="$";
class MyvehicleClass {  // The class
public:
    string brand;  // Attribute
    string model;  // Attribute
    int price;
    int yearModel; // Attribute

    // Method to input vehicle details
    void inputDetails() {
        cout << "Brand Name for Car: ";
        getline(cin, brand);  // Input for brand
        cout << "Model for Car: ";
        getline(cin, model);  // Input for model
        cout << "Price for Car: ";
        // getline(cin >> Global+price);     // Input for year model
        cin >>price;  // Input for year model

        cout << "Year Model for Car: ";
        cin >> yearModel;     // Input for year model
        cin.ignore();         // To consume any remaining newline character
    }

    // Method to display vehicle details
    void displayDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " <<price << endl;
        cout << "Year Model: " << yearModel << endl;
    }
};

int main() {
    vector<string> msg;  // Vector to store messages
    vector<MyvehicleClass> vehicles;  // Vector to store multiple vehicle objects
    string $;

    // Input details for 3 vehicles
    for (int i = 0; i < 3; ++i) {
        cout << "\nEnter details for Car " << i + 1 << ":\n";
        MyvehicleClass vehicle;  // Create a temporary vehicle object
        vehicle.inputDetails();  // Get input for the vehicle
        vehicles.push_back(vehicle);  // Store the vehicle object in the vector

        // Prepare the message for this vehicle
        msg.push_back("Car" + to_string(i + 1) + " Brand: " + vehicle.brand);
        msg.push_back("Car" + to_string(i + 1) + " Model: " + vehicle.model);
        // msg.push_back("Car" + to_string(i + 1) + " Price: " +$+ to_string(vehicle.price));
        msg.push_back("Car" + to_string(i + 1) + " Price: " + Global + to_string(vehicle.price));

        msg.push_back("Car" + to_string(i + 1) + " Year Model: " + to_string(vehicle.yearModel));
    }

    // Create a command to open a new CMD window and display all messages
    string command = "start cmd /K \"echo ";
    for (const string& message : msg) {
        command += message + " && echo ";  // Add "echo" to display each part
    }

    // Close the quote to finish the command, add pause command, and execute
    command += " && pause && exit\"";

    // Use system() to execute the command that opens the new window and shows the message
    system(command.c_str());

    return 0;
}
