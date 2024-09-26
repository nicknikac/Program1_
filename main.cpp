/*
Program 1
Nikola Nikac
CS250
*/

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// Function to display seating chart
void displaySeating(const vector<vector<char>>& seatingChart) {
    cout << "  A B C D\n";
    for (int i = 0; i < seatingChart.size(); i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < seatingChart[i].size(); j++) {
            cout << seatingChart[i][j] << " ";
        }
        cout << endl;
    }
    cout << "O: Available   X: Unavailable\n";
}

// Function to reserve seats
void reserveSeat(vector<vector<char>>& seatingChart, int row, char seat) {
    int seatIndex = seat - 'A';

    if (row < 0 || row >= seatingChart.size() || seatIndex < 0 || seatIndex >= seatingChart[0].size()) {
        throw out_of_range("Invalid row or seat selection.");
    }
    if (seatingChart[row][seatIndex] == 'X') {
        throw runtime_error("Seat is already taken.");
    }

    seatingChart[row][seatIndex] = 'X';  // Mark seat as unavailable
}

int main() {
    int rows = 5;
    int cols = 4;

    vector<vector<char>> seatingChart(rows, vector<char>(cols, 'O'));

    bool continueBooking = true;
    string userChoice;
    displaySeating(seatingChart);

    while (continueBooking) {
        int row;
        char seat;

        cout << "Enter a row (1-" << rows << ") and seat (A-D): ";
        cin >> row >> seat;
        row--;

        // Reserving seat and updating seating chart
        try {
            reserveSeat(seatingChart, row, seat);
            displaySeating(seatingChart);
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

        cout << "Would you like another seat?: ";
        cin >> userChoice;
        if (userChoice != "yes") {
            continueBooking = false;
        }
    }

    // Count seats available
    int availableSeats = 0;
    for (const auto& row : seatingChart) {
        for (char seat : row) {
            if (seat == 'O') {
                availableSeats++;
            }
        }
    }

    cout << "Seating Chart:\n";
    displaySeating(seatingChart);
    cout << availableSeats << " seats are still available.\n";

    return 0;
}
