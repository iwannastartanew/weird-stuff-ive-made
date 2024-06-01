#include <iostream>
#include <string>
using namespace std;
typedef double Daily_Expenses[5];

void display_menu() {
    cout << "Welcome to Daily Expense Tracker by Vohn\n";
    cout << "Guide: You should fill up those 5 categories first and after filling out everything.\n";
    cout << "You will press 6 to find the total sum.\n";
    cout << "How much is your daily allowance:\n";
    cout << "How much do you want to save:\n";
    cout << "1. Food\n";
    cout << "2. Transportation\n";
    cout << "3. Entertainment\n";
    cout << "4. Utilities\n";
    cout << "5. Other\n";
    cout << "6. Total sum of expenses\n";
    cout << "0. Exit\n";
}

void record_expenses(Daily_Expenses expenses) {
    for (int i=0;i<5;++i) {
        cout << "Enter expenses for category " << i+1 << ": ";
        cin >> expenses[i];
    }
}

double calculate_total_expenses(const Daily_Expenses expenses) {
    double total=0.0;
    for (int i=0;i<5;++i) {
        total+=expenses[i];
    }
    return total;
}
void suggest_budget_adjustments(const Daily_Expenses expenses, double daily_allowance, double savings_goal) {
    double total_expenses = calculate_total_expenses(expenses);
    cout << "Total sum of expenses: " << total_expenses << endl;

    if (total_expenses > daily_allowance) {
        cout << "You should adjust your budget accordingly.\n";
    } else if (total_expenses == daily_allowance) {
        cout << "You are managing your budget well. Stay consistent.\n";
    } else {
        cout << "You are saving more than your daily allowance. Great job!\n";
        if (total_expenses + savings_goal < daily_allowance) {
            cout << "You are on track to meet your savings goal.\n";
        } else {
            cout << "You might need to adjust your spending to reach your savings goal.\n";
        }
    }
}

int main()
{
    Daily_Expenses daily_expenses = {0};
    double daily_allowance;
    double savings_goal;
    bool expenses_recorded = false;

    cout << "Enter your daily allowance: ";
    cin >> daily_allowance;
    cout << "Enter your savings goal: ";
    cin >> savings_goal;

    char choice;
    do {
        display_menu();
        cout << "Proceed. Press 1 to allow input: ";
        cin >> choice;

        switch (choice) {
            case '1':
                record_expenses(daily_expenses);
                cout << "Expenses recorded successfully.\n";
                expenses_recorded = true;
                suggest_budget_adjustments(daily_expenses, daily_allowance, savings_goal);
                break;
            case '6':
                if (!expenses_recorded) {
                    cout << "Please record expenses first.\n";
                } else {
                    suggest_budget_adjustments(daily_expenses, daily_allowance, savings_goal);
                }
                break;
            case '0':
                cout << "Program is terminated. Babye\n";
                break;
            default:
                cout << "Error. Please try again";
        }
        if (choice!= '0'&&choice!='6') {
            cout << endl;
        }
        if (expenses_recorded&&choice!='0') {
            break;
        }
    } while (choice!='0');
    return 0;
}
