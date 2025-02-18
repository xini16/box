#ifndef MENUBARUI_H
#define MENUBARUI_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMenu>
#include "Resource.h"

class MenuBarUI : public QWidget {
    Q_OBJECT

public:
    explicit MenuBarUI(QWidget *parent = nullptr);

signals:
    void addResource(Resource *parent, const QString &name, const QString &tag);
    void deleteResource(Resource *resource);
    void renameResource(Resource *resource, const QString &newName);
    void sortResources(const QString &criteria, bool ascending);

private:
    QPushButton *addButton;
    QPushButton *sortButton;
    QPushButton *renameButton;
    QPushButton *deleteButton;
    QMenu *addMenu;
};

#endif // MENUBARUI_H
