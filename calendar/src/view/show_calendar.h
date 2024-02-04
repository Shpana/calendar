#pragma once

#include <vector>

#include "imgui.h"

#include "./select_calendar.h"
#include "./select_month.h"
#include "./view_calendar_slice.h"
#include "../domain/calendar.h"

static void _show_month_calendar() {
	Calendar calendar = select_calendar();

	Month selected_month = select_month();

	view_calendar_slice(calendar, selected_month);
}

static void _show_whole_year_calendar() {
	Calendar calendar = select_calendar();

	view_whole_calendar(calendar);
}

static void _process_calendar() {
	_show_whole_year_calendar();
}

static ImGuiWindowFlags WINDOW_FLAGS =
	ImGuiWindowFlags_NoDecoration |
	ImGuiWindowFlags_NoMove |
	ImGuiWindowFlags_NoResize |
	ImGuiWindowFlags_NoSavedSettings |
	ImGuiWindowFlags_NoBringToFrontOnFocus;

void show_calendar(bool& must_show) {
	
	const ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImGui::SetNextWindowPos(viewport->WorkPos);
	ImGui::SetNextWindowSize(viewport->WorkSize);
	
	if (ImGui::Begin("Calendar", &must_show, WINDOW_FLAGS)) {
		_process_calendar();
	}
	ImGui::End();
}
