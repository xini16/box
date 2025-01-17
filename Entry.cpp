#include "Entry.h"
#include "Boxes.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

Entry::Entry(const QString &entryText, QWidget *parent)
    : QWidget(parent) {

    QHBoxLayout *layout = new QHBoxLayout(this);
    entryLabel = new QLabel(entryText, this);
    QPushButton *deleteButton = new QPushButton("Delete", this);
    layout->addWidget(entryLabel);
    layout->addWidget(deleteButton);

    setLayout(layout);

    connect(deleteButton, &QPushButton::clicked, this, [this]() {
        if (parentWidget()) {
            Box *parentBox = qobject_cast<Box *>(parentWidget());
            if (parentBox) {
                parentBox->removeEntry(this); 
            }
        }
    });
}
