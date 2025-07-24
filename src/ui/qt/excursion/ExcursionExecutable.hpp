#pragma once
#include <qqmlintegration.h>
#include <QList>
#include <QObject>
#include <QQuickItem>

namespace ui::qt::excursion
{
class ExcursionExecutable : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT

public:
    Q_PROPERTY(QString title READ tittle WRITE setTittle NOTIFY tittleChange);

    ExcursionExecutable(QQuickItem* parent = nullptr);
    virtual ~ExcursionExecutable() = default;

    QString tittle();
    void setTittle(QString& tittle);

signals:
    void tittleChange();

public slots:
    QList<QString> findExcursions();

private:
    QString mTittle;
};
}  // namespace ui::qt::excursion
