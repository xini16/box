#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "Boxes.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget mainWindow;

    Box *box1 = new Box("Folder 1", &mainWindow);
    Box *box2 = new Box("Folder 2", &mainWindow);
    Box *box3 = new Box("Folder 3", &mainWindow);    
    // 布局
    QVBoxLayout *layout = new QVBoxLayout(&mainWindow);
    layout->addWidget(box1);
    layout->addWidget(box2);
    layout->addWidget(box3);

    mainWindow.setLayout(layout);
    mainWindow.setWindowTitle("Box Application");
    mainWindow.resize(400, 600);
    mainWindow.show();

    return app.exec();
}
