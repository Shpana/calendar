#pragma once

#include <iostream>
#include <string>

#include "imgui.h"
#include "../domain/date.h"

std::string _generate_date_view(Date* date) {
	return 
		std::to_string(date->get_number()) + "." + 
		std::to_string(date->get_month()) + "." + std::to_string(date->get_year());
}

void view_date_events_menu(Date* handle) {
	static bool should_show = false;
	static Date* selected_date = nullptr;

	if (handle != nullptr) {
		should_show = true;
		selected_date = handle;
	}

	if (should_show) {
		if (ImGui::Begin("Date events", &should_show)) {
			ImGui::Text(_generate_date_view(selected_date).c_str());
			ImGui::Separator();

			for (auto event : selected_date->get_pinned_events()) {
				ImGui::Button(event.name.c_str(), ImVec2(-FLT_MIN, 0.0f));
			}
		}
		ImGui::End();
	}
}
