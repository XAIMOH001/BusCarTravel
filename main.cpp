#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;



class Bus {
public:
    string busNumber;
    string route;
    vector<string> seats;

    // Constructor
    Bus(string number, string routeName) {
        busNumber = number;
        route = routeName;
        seats.resize(20, "Empty"); // Initialize 20 seats as "Empty"
    }
};

// Vector to store all buses
vector<Bus> buses;

// Function to add a bus
void addBus() {
    string number, route;
    cout << "Enter Bus Number:";
    cin.ignore();
    getline(cin, number);
    cout << "Enter Route: ";
    getline(cin, route);

    // Add the new bus to the list
    buses.emplace_back(number, route);

    cout << "Bus added successfully!\n";
    cout << "Added buses:\n";
    for (const auto& bus : buses) {
        cout << "# " <<"Bus no:"<<bus.busNumber << " | Route:" << bus.route << "\n";
    }
}

// Function to view a bus
void viewBuses(){
    if (buses.empty()){
            cout << "No Buses Added" <<endl;
        }else{
            cout << "Added buses:\n";
            for (const auto& bus : buses) {
                cout << "# " << "Bus no:" << bus.busNumber << " | Route:" << bus.route << "\n";
            }
        }

}


// Function to book a seat
void bookSeat() {
    string busNumber;
    cout << "Enter Bus Number: ";
    cin.ignore();
    getline(cin, busNumber);

    // Search for the bus
    Bus* selectedBus = nullptr;
    for (auto& bus : buses){
        if (bus.busNumber == busNumber){
            selectedBus = &bus;
            break;
        }
    }

    if (selectedBus == nullptr) {
        cout << "Bus not found. Please try again.\n";
        return;
    }

    // Show available seats
    cout << "\n=============== Current seat arrangement for Bus " << selectedBus->busNumber << " ===============" << ":\n";
    cout << "\n";
    for (int i = 0; i < selectedBus->seats.size(); i++) {
        cout << " [" << i + 1 << ": " << selectedBus->seats[i] << "] ";
        if ((i+1) % 2 == 0) {
            cout << " \t ";
        }
        if ((i + 1) % 4 == 0) {
            cout << "\n\n";
        }
    }
    // Prompt for seat number
    int seatNumber;
    cout << "\nEnter seat number to book (1-20): ";
    cin >> seatNumber;
    // Validate seat number
    if (seatNumber < 1 || seatNumber > 20) {
        cout << "Invalid seat number. Please enter a number (1-20).\n";
        return;
    }
    // Check if the seat is already booked
    if (selectedBus->seats[seatNumber - 1] != "Empty") {
        cout << "Seat " << seatNumber << " is already booked.\n";
    } else {
        // Book the seat
        string passengerName;
        cout << "Enter passenger's name: ";
        cin.ignore();
        getline(cin, passengerName);

        selectedBus->seats[seatNumber - 1] = passengerName;
        cout << "\n Seat " << seatNumber << " successfully booked for " << passengerName << ".\n";
    }
}

void viewSeats() {
    string busNumber;
    cout << "Enter Bus Number: ";
    cin.ignore();
    getline(cin, busNumber);


    Bus* selectedBus = nullptr;
    for (auto& bus : buses){
        if (bus.busNumber == busNumber){
            selectedBus = &bus;
            break;
        }
    }

    if (selectedBus == nullptr) {
        cout << "Bus not found. Please try again!"<<endl;
        return;
    }


    cout << "\n=============== Seat arrangement for Bus Number: " << selectedBus->busNumber << " ==============="<<endl;
    cout << "\n";
    for (int i = 0; i < selectedBus->seats.size(); i++){
        cout << " [" << i +1 << ": " << selectedBus->seats[i] << "] ";
        if ((i+1) % 2 == 0) {
            cout << " \t ";
        }

        if ((i+1) % 4 == 0) {
            cout << "\n\n";
        }

    }
    cout << "\n";


}

void cancelTicket() {
    string busNumber;
    cout << "You are about to cancel a ticket."<< endl;

    Bus* selectedBus = nullptr;

    //loop till valid input  is entered
    while (true) {
        cout << "Enter Bus Number (or type exit to cancel): ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, busNumber);

        if (busNumber == "exit") {
            cout << "/Operation canceled.\n";
            return;
        }


        for (auto& bus : buses) {
            if (bus.busNumber == busNumber) {
                    selectedBus = &bus;
                    break;//exit loop when bus is found
            }
        }

        if (selectedBus != nullptr) {
            break;
        }else{
            cout << "Bus not found. Please Try Again! \n";//if bus not found
        }

    }

//display current seat arrangement.
    while (true) {
    cout << "\n=============== Seat arrangement for Bus Number: " << selectedBus->busNumber << " ==============="<<endl;
    cout << "\n";
    for (int i = 0; i < selectedBus->seats.size(); i++) {
            cout << " [" << i +1 << ": " << selectedBus->seats[i] << "] ";
            if ((i+1) % 2 == 0) {
                cout << " \t ";
            }
            if ((i+1) % 4 == 0) {
                cout << "\n\n";
            }

    }
    cout << "\n";

    int seatNumber;
        cout << "Enter Seat Number to Cancel: ";
        cin >> seatNumber;

        if (cin.fail() || seatNumber < 1 || seatNumber > selectedBus->seats.size()) {
            cin.clear();
            cin.ignore (numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid seat number. Please enter a number (1-" << selectedBus->seats.size() << ").\n";
            continue;
        }

        if (selectedBus->seats[seatNumber - 1] == "Empty") {
            cout << "Seat " << seatNumber << " is already empty. Please choose another seat.\n";
        } else {
            // cancel ticket
            cout << "Ticket for seat " << seatNumber << " canceled (Passenger: " << selectedBus->seats[seatNumber - 1] << ").\n";
            selectedBus->seats[seatNumber - 1] = "Empty";
            cout << "The seat has been successfully canceled.\n";
            break; // Exit loop after successful cancellation
        }
    }

    // Display final seat arrangement
    cout << "\n=============== Final Seat Arrangement: ===============\n";
    cout << "\n";

    for (size_t i = 0; i < selectedBus->seats.size(); ++i) {
        cout << " [" << i + 1 << ": " << selectedBus->seats[i] << "] ";
        if ((i+1) % 2 == 0){
            cout << " \t ";
        }
        if ((i + 1) % 4 == 0) {
            cout << "\n\n";
        }
    }
    cout << "\n";

}


int main(){

    int choice;//accept integer inputs!

    //display the MENU on the console.
        do{
                cout << "    |" <<"==========================  BusCar Travels Reservation System  ========================="<< "|\n";
                cout << "    |" <<" Choose an option from this List ->>                                                    "<< "|\n";
                cout << "    |" <<"                                                                                        "<< "|\n";
                cout << "    |" <<"                                     1.Add Bus.                                         "<< "|\n";
                cout << "    |" <<"                                     2.View Available Buses.                            "<< "|\n";
                cout << "    |" <<"                                     3.Book a Seat.                                     "<< "|\n";
                cout << "    |" <<"                                     4.View Seats.                                      "<< "|\n";
                cout << "    |" <<"                                     5.Cancel Ticket.                                   "<< "|\n";
                cout << "    |" <<"                                     6.Exit.                                            "<< "|\n";
                cout << "    |" <<"                                                                                        "<< "|\n";
                cout << "    |" <<"                                     Enter your choice:                                 "<< "|\n";
                cout << "    |" <<"========================================================================================"<< "|\n";
                cin >> choice;

                //Input validation.
                 if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter a number (1-6) \n";
                continue;
            }


//Here is what happens when the user inputs a choice.
                switch (choice){
                    case 1:{
                        addBus();
                        break;}
                    case 2:{
                        viewBuses();
                        break;}
                    case 3:{
                        bookSeat();
                        break;}
                    case 4:{
                        viewSeats();
                        break;
                    }
                    case 5:
                        cancelTicket();
                        break;
                    case 6:
                        cout << "Exiting the program...\n";
                        break;
                    default:
                        cout << "Invalid choice. Try again!! \n";
                }
        }while(choice != 6);

    return 0;
}
