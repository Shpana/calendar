#pragma once

#include <string>
#include <functional>

#include <SFML/Graphics.hpp>

class App {

private:
	std::function<void()> _on_process;
	
	sf::RenderWindow* _window;
	sf::Clock _clock;
	unsigned int _frame_rate_limit = 60;
private:
	void _handle_events();
public:
	App(sf::VideoMode mode, std::string title);

	void run();
	void apply_process_handle(std::function<void()> handle);
};
