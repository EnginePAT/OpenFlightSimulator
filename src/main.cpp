#include "App.h"

int main() {
    App app;

    while (!app.window.shouldClose())
    {
        app.update();
        app.render();
    }
    
    app.window.Terminate();
    return 0;
}
