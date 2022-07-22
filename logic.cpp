#include "logic.h"

Logic::Logic()
{

    }

QStringList Logic::getLocalUsers() {
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

void Logic::ParseLocalUsers(QStringList usersList){

}

QString Logic::test() {

    return "test";
}
