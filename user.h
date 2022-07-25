#ifndef USER_H
#define USER_H

#include <QVariant>
#include <qprocess.h>
#include <QObject>
#include <QMetaType>

class User : public QObject
{
    Q_OBJECT
    //Q_GADGET

//    Q_PROPERTY(QString UID READ _UID)
//    Q_PROPERTY(QString GID READ _GID)
//    Q_PROPERTY(QString RegistratorName READ _RegistratorName)
//    Q_PROPERTY(QString FullName READ _FullName)
//    Q_PROPERTY(QString HomeDir READ _HomeDir)
//    Q_PROPERTY(QString LoginEngine READ _LoginEngine)

    //Q_PROPERTY(QString name READ UID)
    //Q_PROPERTY(QList<User*> users READ getLocalUsers NOTIFY usersChanged)
public:
    User();
    //User(QObject *parent = nullptr);
    User(QString _RegistratorName, QString _UID, QString _GID,  QString _FullName, QString _HomeDir, QString _LoginEngine);
    //~User();

    QString UID;
    QString GID;
    QString RegistratorName;
    QString FullName;
    QString HomeDir;
    QString LoginEngine;

//    const QString& _UID() const { return UID; }
//    const QString& _GID() const { return GID; }
//    const QString& _RegistratorName() const { return RegistratorName; }
//    const QString& _FullName() const { return FullName; }
//    const QString& _HomeDir() const { return HomeDir; }
//    const QString& _LoginEngine() const { return LoginEngine; }

    Q_INVOKABLE QList<QVariant> getLocalUsers();
    QStringList getUnparsedLocalUsers();
    QList<User*> ParseLocalUsers(QStringList &usersList);

    //template <typename T>
    QList<QVariant> ToQVariantList(const QList<User*> &list);

//signals:
    //void usersChanged ();
};
Q_DECLARE_METATYPE(User)
//qRegisterMetaType<User>();
#endif // USER_H
