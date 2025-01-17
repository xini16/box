#include "Boxes.h"

Box::Box(const QString &title, QWidget *parent)
    : QWidget(parent), isExpanded(false) {

    QVBoxLayout *frameLayout = new QVBoxLayout(this);

    toggleButton = new QPushButton("▶ " + title, this);
    connect(toggleButton, &QPushButton::clicked, this, &Box::toggleContent);

    addEntryButton = new QPushButton("Add Entry", this);
    addBoxButton = new QPushButton("Add Box", this);
    clearButton = new QPushButton("Clear All", this);
    removeBoxButton = new QPushButton("Remove Box", this);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(toggleButton);
    buttonLayout->addWidget(addEntryButton);
    buttonLayout->addWidget(addBoxButton);
    buttonLayout->addWidget(clearButton);
    buttonLayout->addWidget(removeBoxButton);

    frameLayout->addLayout(buttonLayout);

    contentWidget = new QListWidget(this);
    contentLayout = new QVBoxLayout(contentWidget);
    contentWidget->setMaximumHeight(0);  

    frameLayout->addWidget(contentWidget);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(frameLayout);
    setLayout(mainLayout);

    connect(addEntryButton, &QPushButton::clicked, [this] {
        bool ok;
        QString text = QInputDialog::getText(this, "Add Entry", "Entry Name:", QLineEdit::Normal, "", &ok);
        if (ok && !text.isEmpty()) {
            addEntry(text);
        }
    });

    connect(addBoxButton, &QPushButton::clicked, [this] {
        bool ok;
        QString text = QInputDialog::getText(this, "Add Box", "Folder Name:", QLineEdit::Normal, "", &ok);
        if (ok && !text.isEmpty()) {
            addBox(text);
        }
    });

    connect(clearButton, &QPushButton::clicked, this, &Box::clearAll);
    connect(removeBoxButton, &QPushButton::clicked, this, &Box::removeBox); 
}

void Box::addEntry(const QString &entry) {
    Entry *newEntry = new Entry(entry, this);
    contentLayout->addWidget(newEntry);
}

// void Box::clearEntries() {
//     for (int i = 0; i < contentLayout->count(); ++i) {
//         QWidget *item = contentLayout->itemAt(i)->widget();
//         if (item && dynamic_cast<Entry*>(item)) {
//             item->deleteLater(); 
//         }
//     }
// }

void Box::addBox(const QString &boxName) {
    Box *newBox = new Box(boxName, this);
    contentLayout->addWidget(newBox);
}

// void Box::clearBoxes() {
//     for (int i = 0; i < contentLayout->count(); ++i) {
//         QWidget *widget = contentLayout->itemAt(i)->widget();
//         if (widget) {
//             Box *box = qobject_cast<Box *>(widget);
//             if (box) {
//                 delete box;
//             }
//         }
//     }
// }

void Box::clearAll() {
    for (int i = 0; i < contentLayout->count(); ++i) {
        QWidget *widget = contentLayout->itemAt(i)->widget();
        if (widget) {
            widget->deleteLater();
        }
    }
}

void Box::removeBox() {
    deleteLater();
}

void Box::removeEntry(Entry *entry) {
    for (int i = 0; i < contentLayout->count(); ++i) {
        QWidget *widget = contentLayout->itemAt(i)->widget();
        if (widget == entry) { 
            contentLayout->removeWidget(widget); 
            widget->deleteLater();   
            return;
        }
    }
}

void Box::toggleContent() {
    int contentHeight = contentWidget->sizeHint().height();

    if (isExpanded) {
        contentHeight = 0;
        toggleButton->setText("▶ " + toggleButton->text().mid(2));
    } else {
        toggleButton->setText("▼ " + toggleButton->text().mid(2));
    }

    contentWidget->setMaximumHeight(contentHeight);
    
    addEntryButton->setVisible(!isExpanded);
    addBoxButton->setVisible(!isExpanded);
    clearButton->setVisible(!isExpanded);
    removeBoxButton->setVisible(!isExpanded);

    isExpanded = !isExpanded; 
}
