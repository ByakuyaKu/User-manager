#ifndef USER_H
#define USER_H

#include <qprocess.h>
#include <QObject>

class User : public QObject
{
    Q_OBJECT
public:
    User();
    User(QString _RegistratorName, QString _UID, QString _GID,  QString _FullName, QString _HomeDir, QString _LoginEngine);

    QString UID;
    QString GID;
    QString RegistratorName;
    QString FullName;
    QString HomeDir;
    QString LoginEngine;

    Q_INVOKABLE QList<User> getLocalUsers();
    QStringList getUnparsedLocalUsers();
    QList<User> ParseLocalUsers(QStringList usersList);
};

#endif // USER_H
