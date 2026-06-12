#include <iostream>
#include <vector>
using namespace std;

bool isLeap(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return year % 4 == 0;
}

int countSundays() {
    vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int weekday = 6; 
    int sundayCount = 0;
    
    for (int year = 1901; year <= 2000; year++) {
        vector<int> months = daysInMonth;
        if (isLeap(year)) months[1] = 29;
        
        for (int month = 0; month < 12; month++) {
            
            if (weekday == 6) {  
                sundayCount++;
            }
            
            weekday = (weekday + months[month]) % 7;
        }
    }
    
    return sundayCount;
}

int main() {
    cout << "Sundays on first of month (1901-2000): " << countSundays() << endl;
    return 0;
}