#ifndef BOXES_H
#define BOXES_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class Box : public QWidget {
    Q_OBJECT

public:
    Box(const QString &title, const QString &content, QWidget *parent = nullptr);
    
private slots:
    void toggleContent();

private:
    QPushButton *toggleButton;
    QLabel *contentLabel;
    bool isExpanded;
    QVBoxLayout *mainLayout;
    QWidget *contentWidget;
};

#endif // BOXES_H
