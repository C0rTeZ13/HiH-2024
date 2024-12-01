#include "Authorization.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

void startMain();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Qt_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    CAuthorization authorization;
    authorization.show();

    return a.exec();
}
