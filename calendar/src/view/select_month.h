#pragma once

#include "imgui.h"
#include "../domain/models/month.h"

static int DEFAULT_MONTH = (int)Month::January;

const char* AVAILABLE_MONTH_NAMES[] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"Decemver",
};

Month select_month() {
	static int current_month = DEFAULT_MONTH - 1;

	ImGui::Combo("Month", 
		&current_month, AVAILABLE_MONTH_NAMES, IM_ARRAYSIZE(AVAILABLE_MONTH_NAMES));

	return (Month)(current_month + 1);
}
