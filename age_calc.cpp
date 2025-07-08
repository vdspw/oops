
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <sstream>
using namespace std;

struct User {
    string name;
    string dob;  // Date of Birth in format "YYYY-MM-DD"
    
    int calculateAge() {
        // Parse DOB string (YYYY-MM-DD)
        stringstream ss(dob);
        string year_str, month_str, day_str;
        
        getline(ss, year_str, '-');
        getline(ss, month_str, '-');
        getline(ss, day_str, '-');
        
        int birth_year = stoi(year_str);
        int birth_month = stoi(month_str);
        int birth_day = stoi(day_str);
        
        // Get current date
        auto now = chrono::system_clock::now();
        time_t tt = chrono::system_clock::to_time_t(now);
        tm* local_tm = localtime(&tt);
        
        int current_year = local_tm->tm_year + 1900;
        int current_month = local_tm->tm_mon + 1;
        int current_day = local_tm->tm_mday;
        
        // Calculate age
        int age = current_year - birth_year;
        
        // Adjust if birthday hasn't occurred this year
        if (current_month < birth_month || 
            (current_month == birth_month && current_day < birth_day)) {
            age--;
        }
        
        return age;
    }
};

int main() {
    User user1;
    
    cout << "Enter your name: ";
    getline(cin, user1.name);
    
    cout << "Enter your date of birth (YYYY-MM-DD): ";
    getline(cin, user1.dob);
    
    cout << "\n--- User Information ---" << endl;
    cout << "Name: " << user1.name << endl;
    cout << "Date of Birth: " << user1.dob << endl;
    cout << "Age: " << user1.calculateAge() << " years" << endl;
    
    // Write data to file
    ofstream outFile("user_data.txt");
    if (outFile.is_open()) {
        outFile << "Name: " << user1.name << endl;
        outFile << "Date of Birth: " << user1.dob << endl;
        outFile << "Age: " << user1.calculateAge() << " years" << endl;
        outFile.close();
        cout << "\nData has been written to user_data.txt" << endl;
    } else {
        cout << "\nError: Unable to open file for writing" << endl;
    }
    
    return 0;
}
