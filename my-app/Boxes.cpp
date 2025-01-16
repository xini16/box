#include "Boxes.h"
#include <QPropertyAnimation>

Box::Box(const QString &title, const QString &content, QWidget *parent)
    : QWidget(parent), isExpanded(false) {

    QFrame *frame = new QFrame(this);
    QVBoxLayout *frameLayout = new QVBoxLayout(frame);

    toggleButton = new QPushButton("▶ " + title, this);

    contentWidget = new QWidget(this);
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);
    contentLabel = new QLabel(content, this);
    
    contentLayout->addWidget(contentLabel);
    contentWidget->setMaximumHeight(0);  

    frameLayout->addWidget(toggleButton);
    frameLayout->addWidget(contentWidget);  

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(frame);

    connect(toggleButton, &QPushButton::clicked, this, &Box::toggleContent);
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

    isExpanded = !isExpanded; 
}
