#include <iostream>
#include <string>

using namespace std;

class Waitlist {
private:
    // Node structure inside the Waitlist class
    string party_name;
    Waitlist* next;

    Waitlist* front; // Front of the waitlist (head of the list)
    Waitlist* rear;  // Rear of the waitlist (tail of the list)

public:
    // Constructor
    Waitlist() {
        front = nullptr;
        rear = nullptr;
    }

    // Add a party to the waitlist
    void addParty(const string& party_name) {
        Waitlist* new_node = new Waitlist(); // Create a new node
        new_node->party_name = party_name;
        new_node->next = nullptr;

        if (rear == nullptr) {
            front = rear = new_node; // If the list is empty, front and rear point to the same node
        } else {
            rear->next = new_node; // Otherwise, add the node to the end and update rear
            rear = new_node;
        }
        cout << "Party '" << party_name << "' added to the waitlist." << endl;
    }

    // Seat the first party in the waitlist
    void seatParty() {
        if (front == nullptr) {
            cout << "No parties in the waitlist to seat." << endl;
            return;
        }

        Waitlist* temp = front;
        cout << "Party '" << front->party_name << "' has been seated." << endl;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr; // If the list becomes empty, rear should also be null
        }

        delete temp; // Free memory of the seated party
    }

    // Display the current waitlist
    void displayWaitlist() const {
        if (front == nullptr) {
            cout << "The waitlist is empty." << endl;
            return;
        }

        cout << "Current Waitlist:" << endl;
        Waitlist* temp = front;
        while (temp != nullptr) {
            cout << temp->party_name << endl;
            temp = temp->next;
        }
    }

    // Destructor to free memory
    ~Waitlist() {
        while (front != nullptr) {
            Waitlist* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// Main function
int main() {
    Waitlist restaurantWaitlist;
    int choice;
    string party_name;

    do {
        cout << "\nRestaurant Waitlist System" << endl;
        cout << "1. Add Party to Waitlist" << endl;
        cout << "2. Seat Party" << endl;
        cout << "3. Display Waitlist" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter party name: ";
                cin >> party_name;
                restaurantWaitlist.addParty(party_name);
                break;
            case 2:
                restaurantWaitlist.seatParty();
                break;
            case 3:
                restaurantWaitlist.displayWaitlist();
                break;
            case 4:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
