#include "imgui.h"
#include "imgui-SFML.h"

#include "app.h"
#include "view/show_calendar.h"

int main() {
    App app = {
        sf::VideoMode(800, 600), "Calendar"
    };

    bool must_show = true;

    app.set_on_process_callback([&]() {
        show_calendar(must_show);
    });
    app.run();
}
