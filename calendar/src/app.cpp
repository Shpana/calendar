#include "app.h"

#include "imgui.h"
#include "imgui-SFML.h"

App::App(sf::VideoMode mode, std::string title) {
	_window = 
		std::make_shared<sf::RenderWindow>(mode, title);
	_window->setFramerateLimit(_frame_rate_limit);
}

void App::run() {
	ImGui::SFML::Init(*_window);

	while (_window->isOpen()) {
		_handle_events();
		ImGui::SFML::Update(*_window, _clock.restart());
		_on_process();
		_window->clear();
		ImGui::SFML::Render(*_window);
		_window->display();
	}
	ImGui::SFML::Shutdown();
}

void App::set_on_process_callback(std::function<void()> handle) {
	_on_process = handle;
}

void App::_handle_events() {
	sf::Event event;
	while (_window->pollEvent(event)) {
		ImGui::SFML::ProcessEvent(*_window, event);

		if (event.type == sf::Event::Closed) {
			_window->close();
		}
	}
}
