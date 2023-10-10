#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstring>
#include <limits>

using namespace std;

// Structure to represent a transaction
struct Transaction {
    string type;
    int amount;
    string timestamp;
};

class Bank {
private:
    int client_id = 0;
    int client_balance = 0;
    int client_donation = 0;

    string client_city;
    string client_name;

    static int total_donation;

    vector<Transaction> transactionHistory;

public:
    // Member function to set client details
    void setDetails() {
        cout << "\nClient Id: ";
        cin >> client_id;

        cout << "Client Name: ";
        cin.ignore();
        getline(cin, client_name);

        cout << "Client City: ";
        getline(cin, client_city);
    }

    // Member function for debit operation
    void debit(int amt) {
        client_balance -= amt;
        recordTransaction("Debit", amt);
    }

    // Member function for credit operation
    void credit(int amt) {
        client_balance += amt;
        recordTransaction("Credit", amt);
    }

    // Member function for donation operation
    void donate(int amt) {
        client_donation += amt;
        total_donation += amt;
        client_balance -= amt;
        recordTransaction("Donation", amt);
    }

    // Getter functions
    int getTotalDonation() const { return total_donation; }
    string getname() const { return client_name; }
    int getid() const { return client_id; }
    string getcity() const { return client_city; }
    int getbalance() const { return client_balance; }
    int getdonation() const { return client_donation; }
    static int gettotaldonation() { return total_donation; }

    // Member function to display transaction history
    void displayTransactionHistory() const {
        cout << "\nTransaction History for " << client_name << " (ID: " << client_id << ")\n";
        cout << "---------------------------------------\n";
        cout << "Type\tAmount\tTimestamp\n";
        for (const Transaction &transaction : transactionHistory) {
            cout << transaction.type << "\t" << transaction.amount << "\t" << transaction.timestamp << endl;
        }
    }

private:
    // Member function to record a transaction
    void recordTransaction(const string &type, int amount) {
        time_t now = time(0);
        char *timestamp = ctime(&now);
        timestamp[strlen(timestamp) - 1] = '\0';
        Transaction transaction;
        transaction.type = type;
        transaction.amount = amount;
        transaction.timestamp = timestamp;
        transactionHistory.push_back(transaction);
    }
};

int Bank::total_donation = 0;

int main() {
    vector<Bank> clients;

    int ch = 1;
    cout << "\n\n----------------| Welcome to Naman's Bank of India |----------------\n";
    int selectedClient = -1;
    int selectedClientInfo = -1;
    string city;

    do {
        cout << "\nPress 0. Exit\n";
        cout << "Press 1. Select Client\n";
        cout << "Press 2. View Max Donation\n";
        cout << "Press 3. Search By City\n";
        cout << "Press 4. Total Donation\n";
        cout << "Press 5. Display Info\n";
        cout << "Press 6. Create New Account\n";
        cout << "--> ";cin >> ch;

        switch (ch) {
        case 1:
            cout << "\nSelect Client (1 to " << clients.size() << "): ";
            cin >> selectedClient;
            if (selectedClient >= 1 && static_cast<size_t>(selectedClient) <= clients.size()) {
                cout << "\nSelected client: " << clients[selectedClient - 1].getname() << " (ID: "
                     << clients[selectedClient - 1].getid() << ")\n";
            } else {
                cout << "\nInvalid client selection\n";
            }
            break;

        case 2:
            // Implement logic to find the client with the maximum donation and display their info.
            {
                Bank *clientWithMaxDonation = nullptr;
                int maxDonation = -1;
                for (Bank &client : clients) {
                    if (client.getdonation() > maxDonation) {
                        maxDonation = client.getdonation();
                        clientWithMaxDonation = &client;
                    }
                }
                if (clientWithMaxDonation) {
                    cout << "\nClient with Max Donation: " << clients[selectedClient - 1].getname() << " (ID: "
                         << clients[selectedClient - 1].getid() << ")\n";
                } else {
                    cout << "No clients with donations found.\n";
                }
            }
            break;

        case 3:
            cout << "\nEnter City to Search: ";
            cin.ignore();
            getline(cin, city);
            cout << "\nClients in the city " << city << ":\n";
            for (const Bank &client : clients) {
                if (client.getcity() == city) {
                    cout << client.getname() << " (ID: " << client.getid() << ")\n";
                }
            }
            break;

        case 4:
            cout << "\nTotal Donations: " << Bank::gettotaldonation() << endl;
            break;

        case 5:
            cout << "\nSelect Client Info (1 to " << clients.size() << "): ";
            cin >> selectedClientInfo;
            if (selectedClientInfo >= 1 && static_cast<size_t>(selectedClientInfo) <= clients.size()) {
                clients[selectedClientInfo - 1].displayTransactionHistory();
            } else {
                cout << "\nInvalid client selection\n";
            }
            break;

        case 6:
            // Create a new account
            if (clients.size() < 10) {
                cout << "\nCreate a New Account\n";
                Bank newClient;
                newClient.setDetails();
                clients.push_back(newClient);
            } else {
                cout << "\nAccount limit reached. Cannot create more accounts." << endl;
            }
            break;

        default:
            cout << "\nThank you for using Naman's Bank of India\n";
            cout << "Do visit us Again !\n\n";
        }
    } while (ch != 0);

    system("pause");
    return 0;
}