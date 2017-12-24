#include <QtGui/QGuiApplication>
#include <QtCore/QDir>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QQmlContext>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValueRef>
#include <QJsonArray>
#include <QVariant>
#include <QList>
#include <QVariantList>
#include <QFile>
#include <QString>
#include <cstdio>

const QString INPUT_FILENAME = "stars.json";

QVariantList read_stars_from_json(const QString& filename)
{
	QVariantList res;

	QString val;
	QFile file;
	file.setFileName(filename);
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	val = file.readAll();
	file.close();

	res << val;
	return res;
}


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView viewer;

    // The following are needed to make examples run without having to install the module
    // in desktop environments.
#ifdef Q_OS_WIN
    QString extraImportPath(QStringLiteral("%1/../../../../%2"));
#else
    QString extraImportPath(QStringLiteral("%1/../../../%2"));
#endif
    viewer.engine()->addImportPath(extraImportPath.arg(QGuiApplication::applicationDirPath(),
                                                       QString::fromLatin1("qml")));

    viewer.setSource(QUrl("qrc:/main.qml"));

    viewer.setTitle(QStringLiteral("Interaction"));
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.setColor(QColor(0xfa, 0xfa, 0xfa));
    QVariantList stars = read_stars_from_json(INPUT_FILENAME);
    viewer.rootContext()->setContextProperty("stars", stars);
    viewer.show();

    return app.exec();
}

