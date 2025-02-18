#include "MenuBarUI.h"

MenuBarUI::MenuBarUI(QWidget *parent) : QWidget(parent) {
    QHBoxLayout *layout = new QHBoxLayout(this);

    addButton = new QPushButton("Add", this);
    addMenu = new QMenu(this);
    QAction *addFolderAction = addMenu->addAction("Add Folder");
    QAction *addFileAction = addMenu->addAction("Add File");

    connect(addFolderAction, &QAction::triggered, this, [=]() {
        emit addResource(nullptr, "New Folder", "Folder");
    });

    connect(addFileAction, &QAction::triggered, this, [=]() {
        emit addResource(nullptr, "New File", "File");
    });

    addButton->setMenu(addMenu);

    sortButton = new QPushButton("Sort", this);
    connect(sortButton, &QPushButton::clicked, this, [=]() {
        emit sortResources("name", true);
    });

    renameButton = new QPushButton("Rename", this);
    connect(renameButton, &QPushButton::clicked, this, [=]() {
        emit renameResource(nullptr, "New Name");
    });

    deleteButton = new QPushButton("Delete", this);
    connect(deleteButton, &QPushButton::clicked, this, [=]() {
        emit deleteResource(nullptr);
    });

    layout->addWidget(addButton);
    layout->addWidget(sortButton);
    layout->addWidget(renameButton);
    layout->addWidget(deleteButton);
    setLayout(layout);
}
