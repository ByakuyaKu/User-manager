#ifndef LOGIC_H
#define LOGIC_H
#include <QProcess>
#include <QObject>

class Logic : public QObject
{
    Q_OBJECT
public:
    Logic();
    //explicit Logic(QObject *parent = nullptr);
    Q_INVOKABLE QStringList getLocalUsers();
    void ParseLocalUsers(QStringList usersList);
    Q_INVOKABLE QString test();
private:
QProcess *commandLineP;
};



#endif // LOGIC_H
