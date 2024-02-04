#pragma once

#include <string>
#include <functional>
#include <memory>

#include <SFML/Graphics.hpp>

class App {
public:
	App(sf::VideoMode mode, std::string title);

	void run();
	void set_on_process_callback(std::function<void()> handle);
private:
	std::function<void()> _on_process;
	
	std::shared_ptr<sf::RenderWindow> _window;
	sf::Clock _clock;
	unsigned int _frame_rate_limit = 60;
private:
	void _handle_events();
};
