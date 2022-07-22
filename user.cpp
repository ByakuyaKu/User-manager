#include "user.h"

User::User()
{

}

User::User(QString _RegistratorName, QString _UID, QString _GID, QString _FullName, QString _HomeDir, QString _LoginEngine)
{
    UID = _UID;
    GID = _GID;
    RegistratorName = _RegistratorName;
    FullName = _FullName;
    HomeDir = _HomeDir;
    LoginEngine = _LoginEngine;
}

Q_INVOKABLE QList<User> User::getLocalUsers(){
    QStringList unparsedLocalUsers = getUnparsedLocalUsers();

    QList<User> parsedLocalUsers = ParseLocalUsers(unparsedLocalUsers);

    return parsedLocalUsers;
}

QStringList User::getUnparsedLocalUsers() {
    QProcess clp;
    QStringList usersList;

    clp.start("less", QStringList() << "/etc/passwd");

    if (!clp.waitForStarted())
        return usersList;

    if (!clp.waitForFinished())
        return usersList;

    QString result = clp.readAll();
    QStringRef res = &result;

    usersList = result.split(QLatin1Char('\n'));

    return usersList;
}

QList<User> User::ParseLocalUsers(QStringList usersList){
    QList<User> parsedUsersList;

    for(int i = 0; i < usersList.length(); i++)
    {
        QStringList userInfo = usersList[i].split(QLatin1Char(':'));
        User curUser = User(userInfo[0], userInfo[2], userInfo[3], userInfo[4], userInfo[5], userInfo[6]);
        parsedUsersList.append(curUser);
    }

    return parsedUsersList;
}
