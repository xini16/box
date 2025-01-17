#ifndef ENTRY_H
#define ENTRY_H

#include <QWidget>
#include <QLabel>
#include <QString>

class Entry : public QWidget {
    Q_OBJECT

public:
    explicit Entry(const QString &entryText, QWidget *parent = nullptr);

private:
    QLabel *entryLabel;
};

#endif // ENTRY_H
