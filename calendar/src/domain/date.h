#pragma once

#include <vector>

#include "models/events.h"

class Date {

private:
    int _day, _year;
    std::vector<Event> _pinned_events;
public:
    int get_month();
    int get_day();
    int get_year();
    int get_number();
    int get_weekday();

    Date(int day, int year) :
        _day(day), _year(year) {}

    void pinn_event(Event event);
    const std::vector<Event>& get_pinned_events();
};
