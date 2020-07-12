#include "app/app.h"

int main(int argc, char *argv[])
{
    std::unique_ptr<App> app(new App(argc, argv));
    app->init();
    return app->run();
}
