#include "window.h"

#include <QApplication>

int main(int argc, char **argv) {

    QApplication app (argc, argv);
    app.setApplicationName("Chess-Inator");

    Window win{Window()};
    win.show();

    return app.exec();

}
