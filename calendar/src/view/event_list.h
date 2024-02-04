#pragma once

#include <vector>

#include "../domain/calendar.h"
#include "../domain/models/events.h"
#include "../domain/models/month.h"

std::vector<std::pair<Event, Calendar::Condition>> EVENT_LIST = {
	{
		{
			"Programming day"
		},
		[](Date& date) -> bool {
			return date.get_day() == 256;
		}
	},
	{
		{
			"New Year"
		},
		[](Date& date) -> bool {
			return date.get_number() == 1 && (Month)date.get_month() == Month::January;
		}
	},
	{
		{
			"Valentine's Day"
		},
		[](Date& date) -> bool {
			return date.get_number() == 14 && (Month)date.get_month() == Month::February;
		}
	},
	{
		{
			"29 February!!!"
		},
		[](Date& date) -> bool {
			return date.get_number() == 29 && (Month)date.get_month() == Month::February;
		}
	},
};
