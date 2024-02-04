#pragma once

#include <vector>
#include <string>

#include "imgui.h"

#include "../domain/calendar.h"
#include "../domain/date.h"
#include "../domain/models/month.h"

#include "./view_date_events_menu.h"

static std::vector<std::string> WEEK_DAY_ALIASES = {
	"Monday", 
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday", 
	"Sanday"
};

static std::vector<std::string> MONTH_ALIASES = {
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

void _define_table_columns() {
	for (auto alias : WEEK_DAY_ALIASES) {
		ImGui::TableSetupColumn(alias.c_str(), ImGuiTableColumnFlags_NoResize);
	}
	ImGui::TableHeadersRow();
}

static ImGuiTableFlags TABLE_FLAGS =
	ImGuiTableFlags_ScrollY |
	ImGuiTableFlags_RowBg |
	ImGuiTableFlags_BordersOuter |
	ImGuiTableFlags_BordersV |
	ImGuiTableFlags_Resizable |
	ImGuiTableFlags_Reorderable |
	ImGuiTableFlags_Hideable;

void _select_date(Date* date, Date*& selection) {
	static float button_height = 16.0f;
	
	if (date->get_pinned_events().size() > 0) {
		ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(255, 100, 100, 255));
	}

	if (ImGui::Button(std::to_string(date->get_number()).c_str(), ImVec2(-FLT_MIN, button_height))) {
		selection = date;
	}

	if (date->get_pinned_events().size() > 0) {
		ImGui::PopStyleColor();
	}
}

Date* _view_horizontal_dates_grid(const std::vector<Date*>& dates) {
	Date* selected_date = nullptr;

	if (ImGui::BeginTable(std::to_string(dates[0]->get_month()).c_str(), 7, TABLE_FLAGS)) {
		_define_table_columns();

		int start_month_index = dates[0]->get_weekday();
		int row = -1;

		for (auto& date : dates) {
			if (row != (start_month_index + date->get_number() - 2) / 7) {
				ImGui::TableNextRow();
				row = (start_month_index + date->get_number() - 2) / 7;
			}
			ImGui::TableSetColumnIndex(date->get_weekday() - 1);

			_select_date(date, selected_date);
		}
		ImGui::EndTable();
	}

	return selected_date;
}

Date* _view_vertical_dates_grid(const std::vector<Date*>& dates) {

	Date* selected_date = nullptr;

	if (ImGui::BeginTable(std::to_string(dates[0]->get_month()).c_str(), 7, TABLE_FLAGS)) {
		std::vector<Date*> dates_by_weekday[7];

		for (auto& date : dates) {
			dates_by_weekday[date->get_weekday() - 1].push_back(date);
		}

		int start_month_index = dates[0]->get_weekday();

		for (int i = 0; i < 7; i++) {
			ImGui::TableNextRow();
			ImGui::TableSetColumnIndex(0);
			ImGui::Text(WEEK_DAY_ALIASES[i].c_str());

			for (int k = 0; k < dates_by_weekday[i].size(); k++) {
				int delta = (start_month_index - 1 > i) ? 1 : 0;
				ImGui::TableSetColumnIndex(k + 1 + delta);

				_select_date(dates_by_weekday[i][k], selected_date);
			}
		}
		ImGui::EndTable();
	}

	return selected_date;
}

void view_calendar_slice(Calendar& calendar, Month month) {
	std::vector<Date*> dates_to_view;

	for (auto& date : calendar.get_content()) {
		if (date->get_month() == (int)month) {
			dates_to_view.push_back(date);
		}
	}

	ImGui::NewLine();
	view_date_events_menu(_view_horizontal_dates_grid(dates_to_view));
}

void view_whole_calendar(Calendar& calendar) {
	std::vector<Date*> dates_to_view_by_month[12];

	for (auto& date : calendar.get_content()) {
		dates_to_view_by_month[date->get_month() - 1].push_back(date);
	}

	Date* selected_date = nullptr;
	if (ImGui::BeginTable("whole calendar grid", 4, TABLE_FLAGS)) {
		for (int i = 0; i < 3; i++) {
			ImGui::TableNextRow();
			for (int j = 0; j < 4; j++) {
				ImGui::TableSetColumnIndex(j);
				ImGui::Text(MONTH_ALIASES[j + i * 4].c_str());
				
				Date* selection = 
					_view_vertical_dates_grid(dates_to_view_by_month[j + i * 4]);

				if (selection != nullptr) {
					selected_date = selection;
				}
			}
		}
		view_date_events_menu(selected_date);
		
		ImGui::EndTable();
	}
}