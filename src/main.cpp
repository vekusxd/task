#include <QApplication>
#include "../include/window.hpp"

int main(int argc, char **argv){
    try{
        QApplication app(argc, argv);

        window window;
        window.resize(535, 600);

        window.show();

        return app.exec();
    }
    catch(std::exception& ex){
        qDebug() << ex.what();
    }
}
