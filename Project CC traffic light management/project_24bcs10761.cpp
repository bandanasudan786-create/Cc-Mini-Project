#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"

struct Signal {
    int id, vehicles, greenTime;
};

int calculateTime(int v) {
    if (v < 10) return 5;
    else if (v < 20) return 10;
    else return 15;
}

void display(vector<Signal>& s) {
    cout << "\n===== TRAFFIC STATUS =====\n";
    for (auto &x : s) {
        cout << "Signal " << x.id
             << " | Vehicles: " << x.vehicles
             << " | Time: " << x.greenTime << " sec\n";
    }
}

void simulate(vector<Signal>& s) {
    cout << "\nStarting Simulation...\n";

    for (auto &x : s) {
        cout << GREEN << "\n[GREEN] Signal " << x.id << RESET << "\n";

        for (int t = x.greenTime; t > 0; t--) {
            cout << "Time Left: " << t << " sec" << endl;
            Sleep(1000);
        }

        cout << YELLOW << "[YELLOW] Signal " << x.id << RESET << endl;
        Sleep(2000);

        cout << RED << "[RED] Signal " << x.id << RESET << endl;
    }

    cout << "\nCycle Complete!\n";
}

void update(vector<Signal>& s) {
    cout << "\nUpdate Vehicles:\n";
    for (auto &x : s) {
        cout << "Signal " << x.id << ": ";
        cin >> x.vehicles;
        x.greenTime = calculateTime(x.vehicles);
    }
}

int main() {
    int n;
    cout << "SMART TRAFFIC LIGHT SYSTEM\n";
    cout << "Enter number of signals: ";
    cin >> n;

    vector<Signal> s(n);

    for (int i = 0; i < n; i++) {
        s[i].id = i + 1;
        cout << "Vehicles at Signal " << i + 1 << ": ";
        cin >> s[i].vehicles;
        s[i].greenTime = calculateTime(s[i].vehicles);
    }

    int ch;

    while (true) {
        cout << "\n1. View Status\n2. Run Simulation\n3. Update\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        if (ch == 1) display(s);
        else if (ch == 2) simulate(s);
        else if (ch == 3) update(s);
        else if (ch == 4) break;
        else cout << "Invalid!\n";
    }

    cout << "\nOpening Visual UI...\n";
    Sleep(1000);
    system("start \"\" \"project24bcs10761.html\"");

    return 0;
}