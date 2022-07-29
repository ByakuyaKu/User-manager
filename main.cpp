#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <logic.h>
#include <user.h>
#include <QQmlContext>
#include <QQuickView>
#include <stringlistmodel.h>
//#include <Model/variantmaptablemodel.h>

#include <QAbstractItemModel>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    //QQuickView view;
    Logic appLogic;

    engine.rootContext()->setContextProperty("logic", &appLogic);
    //view.rootContext()->setContextProperty("v", &appLogic);
    //view.setSource(QUrl::fromLocalFile("MyItem.qml"));
    //view.show();
    User user;
    engine.rootContext()->setContextProperty("user", &user);

    //qmlRegisterType<VariantMapTableModel>("VariantMapTableModel", 0, 1, "VariantMapTableModel");

    //VariantMapTableModel* model = new VariantMapTableModel(&app);
    //model->registerColumn(new SimpleColumn("UID"));
    //model->registerColumn(new SimpleColumn("Name"));

    //QVariantMap users;
    //users.insert("UID", 1);
    //users.insert("Name", "123");
    //model->addRow(users);

    //engine.rootContext()->setContextProperty("model", model);

    engine.load(url);

    return app.exec();
}
