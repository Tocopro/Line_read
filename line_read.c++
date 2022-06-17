
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int output = 1;
int number;
std::fstream& GotoLine(std::fstream& reprint, unsigned int num)
{
    reprint.seekg(std::ios::beg);
    for(int i = 0; i < num - 1; ++i)
    {
        reprint.ignore(std::numeric_limits<streamsize>::max(),'\n');
    }
    return reprint;
}
int main() {
    fstream sonnets, reprint, reprint2;
    sonnets.open(R"(C:\Users\NEAK\Documents\Speare\sonnets_file.txt)", ios::in);
    reprint.open(R"(C:\Users\NEAK\Documents\Speare\solution_file.txt)", ios::out);
    int count = 1;
    string line;
    if (sonnets.is_open()) {
        while (getline(sonnets, line)) {
            if (reprint.is_open()) {
                reprint << count << " " << line << "\n";
                count += 1;
            }

        }
    }
    sonnets.close();
    reprint.close();

    cout << "Enter Number: ";
    cin >> number;
    cout << number;
    reprint.open(R"(C:\Users\NEAK\Documents\Speare\sonnets_file.txt)", ios::in);
    reprint2.open(R"(C:\Users\NEAK\Documents\Speare\reprint_file.txt)", ios::out);
    GotoLine(reprint, 5);
    string line5;
    reprint >> line5;
    cout << line5;
    cin.get();
    return 0;
}
