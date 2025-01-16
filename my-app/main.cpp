#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include "Boxes.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;

    Box *box1 = new Box("Box 1", "content for box 1.", &window);
    Box *box2 = new Box("Box 2", "content for box 2.", &window);
    Box *box3 = new Box("Box 3", "content for box 3.", &window);

    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(box1);
    layout->addWidget(box2);
    layout->addWidget(box3);

    window.setLayout(layout);
    window.show();

    return app.exec();
}
