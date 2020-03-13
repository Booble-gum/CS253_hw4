#include "Ratio.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    Ratio R1 = Ratio(-50, -100);
    Ratio R2 = Ratio(25, -50);
    Ratio R3 = Ratio(0, 250);
    cout << R1 << R2 << R3;

    cout << Ratio::normalize(R1);
    cout << Ratio::normalize(R2);
    cout << Ratio::normalize(R3);
    cout << Ratio(3,4).ratio() << "\n";

    cout << Ratio::add(R1, R2);

/*
    ifstream in("data");
    if (!in) {
        cerr << "Can’t open data\n";
        return 1;
    }
    while (in >> r)
        cout << "»»» " << r << '\n';
        */
    return 0;
}
