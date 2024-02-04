#pragma once

#include "imgui.h"
#include "./event_list.h"

#define DEFAULT_YEAR 2022

static int _select_year() {
	static int current_year = DEFAULT_YEAR;
	ImGui::InputInt("Year", &current_year);
	return current_year;
}

Calendar& select_calendar() {
	static int previous_year = DEFAULT_YEAR;

	int current_year = _select_year();

	static Calendar calendar = {
		current_year, EVENT_LIST
	};

	if (current_year != previous_year) {
		previous_year = current_year;

		calendar = Calendar(
			current_year, EVENT_LIST
		);
	}
	return calendar;
}
