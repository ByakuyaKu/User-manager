#include "user.h"
#include<QDebug>

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

Q_INVOKABLE QList<QVariant> User::getLocalUsers(){
    QStringList unparsedLocalUsers = getUnparsedLocalUsers();

    QList<User*> parsedLocalUsers = ParseLocalUsers(unparsedLocalUsers);

    return ToQVariantList(parsedLocalUsers);
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

QList<User*> User::ParseLocalUsers(QStringList &usersList){
    QList<User*> parsedUsersList;
    //qInfo() << usersList[0];
    for(int i = 0; i < usersList.length()-1; i++)
    {
        //qInfo() << usersList[i];
        QStringList userInfo = usersList[i].split(QLatin1Char(':'));
        User curUser = User(userInfo[0], userInfo[2], userInfo[3], userInfo[4], userInfo[5], userInfo[6]);
        parsedUsersList.append(&curUser);

        //qInfo() << (curUser.HomeDir + " | " + curUser.FullName + " | " + curUser.GID + " | " + curUser.LoginEngine + " || ");
    }
    //qInfo() << "parsedUsersList.length()";
    return parsedUsersList;
}

//template <typename T>
QList<QVariant> User::ToQVariantList(const QList<User*> &list){

    QVariantList convertedList;
    for(int i = 0; i < list.length(); i++){
     //foreach( const T &item, list )
        //QVariant tmp;
        convertedList << QVariant::fromValue(list[i]);
        //convertedList << tmp.setValue(list[i]);
        //qInfo() << (convertedList[i]);
    }
         //convertedList << QVariant::fromValue(item);
    //qInfo() << convertedList.length();
    return convertedList;
}
