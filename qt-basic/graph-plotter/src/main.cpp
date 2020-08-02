#include <QtGui/QtGui>
#include <QtQuick/QtQuick>

#include "beziercurve.hpp"

//! [1]


int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<BezierCurve>("CustomGeometry", 1, 0, "BezierCurve");

    QQuickView view;
    QSurfaceFormat format = view.format();
    format.setSamples(16);
    view.setFormat(format);
    view.setSource(QUrl(QStringLiteral("qrc:/res/main.qml")));
    view.show();

    app.exec();
}
//! [1]