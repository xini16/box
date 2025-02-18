#include "ResourceManager.h"

ResourceManager::ResourceManager(QObject *parent) : QObject(parent) {}

void ResourceManager::addResource(Resource *parent, const QString &name, const QString &tag) {
    Resource *newResource = new Resource(name, tag, parent);
    if (parent) {
        parent->addChild(newResource);
    } else {
        rootResources.append(newResource);
    }
    emit resourceUpdated();
}

void ResourceManager::deleteResource(Resource *resource) {
    if (resource->getParent()) {
        resource->getParent()->removeChild(resource);
    } else {
        rootResources.removeAll(resource);
    }
    delete resource;
    emit resourceUpdated();
}

void ResourceManager::renameResource(Resource *resource, const QString &newName) {
    if (resource) {
        resource->setName(newName);
        emit resourceUpdated();
    }
}

void ResourceManager::sortResources(const QString &criteria, bool ascending) {
    auto compare = [criteria, ascending](Resource *a, Resource *b) {
        if (criteria == "name")
            return ascending ? a->getName() < b->getName() : a->getName() > b->getName();
        else
            return ascending ? a->getTag() < b->getTag() : a->getTag() > b->getTag();
    };

    std::sort(rootResources.begin(), rootResources.end(), compare);
    emit resourceUpdated();
}

QList<Resource *> ResourceManager::getRootResources() const {
    return rootResources;
}

void ResourceManager::createTestData() {
    Resource *folder1 = new Resource("Folder A", "Folder");
    Resource *folder2 = new Resource("Folder B", "Folder");

    Resource *file1 = new Resource("File A1", "Type A", folder1);
    Resource *file2 = new Resource("File B1", "Type B", folder2);

    folder1->addChild(file1);
    folder2->addChild(file2);

    rootResources.append(folder1);
    rootResources.append(folder2);

    emit resourceUpdated();
}
