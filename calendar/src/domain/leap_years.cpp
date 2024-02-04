#include "./leap_years.h"

bool _is_leap_year(int year) {
    if (year % 4 != 0)
        return false;
    else if (year % 100 != 0)
        return true;
    else if (year % 400 != 0)
        return false;
    else
        return true;
}

int _get_days_count_in_year(int year) {
    if (_is_leap_year(year))
        return 366;
    else
        return 365;
}

int _get_days_in_month(int month, int year) {
    switch (month) {
    case 1: return 31;
    case 2:
        return (_is_leap_year(year)) ? 29 : 28;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    default:
        return 0;
    }
}
