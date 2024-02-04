#pragma once 

#include <vector>
#include <functional>

#include "./date.h"
#include "models/events.h"

class Calendar {

private:
    std::vector<Date*> _calendar;
public:
    using Condition = std::function<bool(Date&)>;
public:
    const std::vector<Date*>& get_content();

    Calendar(
        int year, const std::vector<std::pair<Event, Condition>>& event_list);
};
