#ifndef BOXES_H
#define BOXES_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QMessageBox>
#include <QInputDialog>
#include "Entry.h"

class Box : public QWidget {
    Q_OBJECT

public:
    explicit Box(const QString &title, QWidget *parent = nullptr);
    void addEntry(const QString &entry);
    void addBox(const QString &boxName);
    void removeBox();
    void removeEntry(Entry *entry);


private slots:
    void toggleContent();
    void clearAll();

private:
    QPushButton *toggleButton;
    QPushButton *addEntryButton;
    QPushButton *addBoxButton;
    QPushButton *removeBoxButton;
    QPushButton *clearButton;
    bool isExpanded;
    QVBoxLayout *mainLayout;
    QListWidget *contentWidget;
    QVBoxLayout *contentLayout;

    // void clearEntries();
    // void clearBoxes();
};

#endif // BOXES_H
