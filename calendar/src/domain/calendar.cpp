#include "./calendar.h"

#include "./leap_years.h"

const std::vector<Date*>& Calendar::get_content() {
    return _calendar;
}

Calendar::Calendar(
    int year, const std::vector<std::pair<Event, Condition>>& event_list) {

    for (int day = 1; day <= _get_days_count_in_year(year); day++) {
        Date* date =
            new Date{ day, year };

        for (auto& elem : event_list)
            if (elem.second(*date))
                date->pinn_event(elem.first);

        _calendar.push_back(date);
    }
}
