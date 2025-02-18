#ifndef RESOURCE_H
#define RESOURCE_H

#include <QString>
#include <QList>

class Resource {
public:
    Resource(const QString &name, const QString &tag, Resource *parent = nullptr);

    // 访问器
    QString getName() const;
    QString getTag() const;
    QList<Resource *> getChildren() const;
    Resource *getParent() const;
    bool isFolder() const;

    // 修改器
    void setName(const QString &name);
    void setTag(const QString &tag);
    void addChild(Resource *child);
    void removeChild(Resource *child);
    bool hasChildren() const;

private:
    QString name;
    QString tag;
    Resource *parent;
    QList<Resource *> children;
};

#endif // RESOURCE_H
