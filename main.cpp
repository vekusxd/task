#include <QApplication>
#include "window.hpp"

int main(int argc, char **argv){
    QApplication app(argc, argv);

    window window;
    window.resize(535, 600);

    window.show();

    return app.exec();
}
