#include <iostream>
#include <ctime>
#include <cstdlib>

typedef struct {
    int numbers[6];
} lotto_ticket;
typedef lotto_ticket lt;
lt generate_numbers(int min, int max, int count) {
    lt ticket;
    for (int i=0; i<count; ++i) {
        ticket.numbers[i] = std::rand()%(max - min + 1) + min;
    }
    return ticket;
}
int main() {
    using namespace std;

    std::srand(static_cast<unsigned>(std::time(0)));

    cout << "There are several lotto games that you can play, choose:\n";
    cout << "1. Ultra Lotto 6/58\n";
    cout << "2. Grand Lotto 6/55\n";
    cout << "3. Super Lotto 6/49\n";
    cout << "4. Mega Lotto 6/45\n";
    cout << "5. Lotto 6/42\n";
    cout << "6. 3D Lotto\n";
    cout << "7. 2D Lotto\n";
    cout << "Which do you want to choose: ";

    int choice;
    cin >> choice;

    lt ticket;

    switch (choice) {
        case 1:
            ticket = generate_numbers(1, 58, 6);
            cout << "Aight! Here are the 6 numbers for Ultra Lotto 6/58: ";
            break;
        case 2:
            ticket = generate_numbers(1, 55, 6);
            cout << "Aight! Here are the 6 numbers for Grand Lotto 6/55: ";
            break;
        case 3:
            ticket = generate_numbers(1, 49, 6);
            cout << "Aight! Here are the 6 numbers for Super Lotto 6/49: ";
            break;
        case 4:
            ticket = generate_numbers(1, 45, 6);
            cout << "Aight! Here are the 6 numbers for Mega Lotto 6/45: ";
            break;
        case 5:
            ticket = generate_numbers(1, 42, 6);
            cout << "Aight! Here are the 6 numbers for Lotto 6/42: ";
            break;
        case 6:
            ticket = generate_numbers(0, 9, 3);
            cout << "Aight! Here are the 3 numbers for 3D Lotto: ";
            break;
        case 7:
            ticket = generate_numbers(1, 31, 2);
            cout << "Aight! Here are the 2 numbers for 2D Lotto: ";
            break;
        default:
            cout << "Invalid choice!";
            return 1;
    }

    for (int i = 0; i < 6; ++i) {
        cout << (i == 0 ? "" : "-") << ticket.numbers[i];
    }
    cout << endl;
    return 0;
}
