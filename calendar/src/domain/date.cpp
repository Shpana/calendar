#include "./date.h"

#include <cmath>
#include "./leap_years.h"

int Date::get_month() {
    int day = _day;
    int current_month = 1;

    while (day > _get_days_in_month(current_month, _year)) {
        day -= _get_days_in_month(current_month, _year);
        current_month++;
    }
    return current_month;
}

int Date::get_day() {
    return _day;
}

int Date::get_year() {
    return _year;
}

int Date::get_number() {
    int month = 1;
    int current_day = _day;

    while (current_day > _get_days_in_month(month, _year)) {
        current_day -= _get_days_in_month(month, _year);
        month++;
    }
    return current_day;
}

int Date::get_weekday() {
    int delta = 0;
    int current_year = _year;

    while (current_year != 2022) {
        int sign =
            (2022 - current_year) / std::abs(2022 - current_year);

        delta += -sign * _get_days_count_in_year(current_year);
        current_year += sign;
    }
    delta += _day - 1;

    return (5 + ((delta % 7) + 7) % 7) % 7 + 1;
}

void Date::pinn_event(Event event) {
    _pinned_events.push_back(event);
}

const std::vector<Event>& Date::get_pinned_events() {
    return _pinned_events;
}
