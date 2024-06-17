#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm> // For std::find and std::sort

struct lotto_ticket {
    int numbers[6];
};

lotto_ticket generate_numbers(int min, int max, int count) {
    lotto_ticket ticket;
    std::vector<int> chosen;

    while (chosen.size() < count) {
        int num = std::rand() % (max - min + 1) + min;
        if (std::find(chosen.begin(), chosen.end(), num) == chosen.end()) {
            chosen.push_back(num);
        }
    }

    std::sort(chosen.begin(), chosen.end()); // Sort for output consistency
    for (int i = 0; i < count; ++i) {
        ticket.numbers[i] = chosen[i];
    }

    return ticket;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    std::cout << "There are several lotto games that you can play, choose:\n";
    std::cout << "1. Ultra Lotto 6/58\n";
    std::cout << "2. Grand Lotto 6/55\n";
    std::cout << "3. Super Lotto 6/49\n";
    std::cout << "4. Mega Lotto 6/45\n";
    std::cout << "5. Lotto 6/42\n";
    std::cout << "6. 3D Lotto\n";
    std::cout << "7. 2D Lotto\n";
    std::cout << "Which do you want to choose: ";

    int choice;
    std::cin >> choice;

    lotto_ticket ticket;

    switch (choice) {
        case 1:
            ticket = generate_numbers(1, 58, 6);
            std::cout << "Aight! Here are the 6 numbers for Ultra Lotto 6/58: ";
            break;
        case 2:
            ticket = generate_numbers(1, 55, 6);
            std::cout << "Aight! Here are the 6 numbers for Grand Lotto 6/55: ";
            break;
        case 3:
            ticket = generate_numbers(1, 49, 6);
            std::cout << "Aight! Here are the 6 numbers for Super Lotto 6/49: ";
            break;
        case 4:
            ticket = generate_numbers(1, 45, 6);
            std::cout << "Aight! Here are the 6 numbers for Mega Lotto 6/45: ";
            break;
        case 5:
            ticket = generate_numbers(1, 42, 6);
            std::cout << "Aight! Here are the 6 numbers for Lotto 6/42: ";
            break;
        case 6:
            ticket = generate_numbers(0, 9, 3);
            std::cout << "Aight! Here are the 3 numbers for 3D Lotto: ";
            for (int i = 0; i < 3; ++i) {
                std::cout << (i == 0 ? "" : "-") << ticket.numbers[i];
            }
            std::cout << std::endl;
            break;
        case 7:
            ticket = generate_numbers(1, 31, 2);
            std::cout << "Aight! Here are the 2 numbers for 2D Lotto: ";
            break;
        default:
            std::cout << "Invalid choice!";
            return 1;
    }
    if (choice != 6) { 
        for (int i = 0; i < 6; ++i) {
            std::cout << (i == 0 ? "" : "-") << ticket.numbers[i];
        }
        std::cout << std::endl;
    }
    return 0;
}
