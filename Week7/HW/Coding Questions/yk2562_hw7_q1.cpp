#include <iostream>
#include <string>

// Constants: Week
const int MONDAY = 1;
const int SATURDAY = 6;
const int SUNDAY = 7;
const int DAYS_IN_WEEK = 7;

// Constants: Month
const int JANUARY = 1;
const int FEBRUARY = 2;
const int MARCH = 3;
const int APRIL = 4;
const int MAY = 5;
const int JUNE = 6;
const int JULY = 7;
const int AUGUST = 8;
const int SEPTEMBER = 9;
const int OCTOBER = 10;
const int NOVEMBER = 11;
const int DECEMBER = 12;

// Function Declarations
int printMonthCalender(int numOfDays, int startingDay);
bool isLeapYear(int year);
void printYearCalendar(int year, int startingDay);
std::string monthString(int month);
int numOfDaysInMonth(int month, int year);

int main() {
    int year = 0, startingDay = 0; // initialized to 0 to trigger positive input check

    // Check for positive input
    while (year < 1) {
        std::cout << "Please enter a year: ";
        std::cin >> year;
    }
    while (startingDay < 1) {
        std::cout << "Please enter starting day as a number (ex: Monday = 1, Tuesday = 2, ...etc.): ";
        std::cin >> startingDay;
    }

    std::cout << std::endl;
    printYearCalendar(year, startingDay);

    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {
    int day = 1; // initialized to first day of any month
    int lastDay;
    int numOfRows = startingDay >= SATURDAY ? 7 : 6; // days overflow onto 7th row when month starts on a Saturday

    // Rows
    for (int i = 0; i < numOfRows; i++) {
        // Row to display day of the week label
        if (i == 0) {
            std::cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun";
        }else if (i == 1) {
            // Starting day spacing offset
            for (int j = 1; j < startingDay; j++) {
                std::cout << " \t";
            }
            // Days
            for (int j = 0; j <= DAYS_IN_WEEK - startingDay; j++) {
                std::cout << day << "\t";
                day++;
            }
        }else {
            // Days
            for (int j = MONDAY; j <= SUNDAY; j++) {
                if (day == numOfDays) {
                    // if month's last day is a Sunday, restart from beginning of the week
                    lastDay = j;
                }

                if (day < numOfDays + 1) {
                    std::cout << day << "\t";
                    day++;
                }
            }
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
    return lastDay;
}

bool isLeapYear(int year) {
   return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void printYearCalendar(int year, int startingDay) {
    for (int month = JANUARY; month <= DECEMBER; month++) {
        std::cout << monthString(month) << " " << year << "\n";
        startingDay = printMonthCalender(numOfDaysInMonth(month, year), startingDay);
        // If last month ended on a Sunday, reset startingDay to Monday, otherwise go on to the next day
        startingDay = startingDay == SUNDAY ? MONDAY : ++startingDay;
    }
}

// Helper function to convert month int to string
std::string monthString(int month) {
    switch (month) {
        case JANUARY:
            return "January";
        case FEBRUARY:
            return "February";
        case MARCH:
            return "March";
        case APRIL:
            return "April";
        case MAY:
            return "May";
        case JUNE:
            return "June";
        case JULY:
            return "July";
        case AUGUST:
            return "August";
        case SEPTEMBER:
            return "September";
        case OCTOBER:
            return "October";
        case NOVEMBER:
            return "November";
        case DECEMBER:
            return "December";
        default:
            break;
    }
}

int numOfDaysInMonth(int month, int year) {
    if (month == JANUARY || month == MARCH || month == MAY || month == JULY || month == AUGUST || month == OCTOBER || month == DECEMBER) {
        return 31;
    }else if (month == FEBRUARY) {
        return isLeapYear(year) ? 29 : 28;
    }else {
        return 30;
    }
}