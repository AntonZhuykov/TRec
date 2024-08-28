#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "TRec_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    // a.setStyleSheet("QPushButton {background-color: qlineargradient(x1:0,y1:0,x:0,y2:0, stop:0 #DADADA, stop:1 #DADADA);"
    //                 "border: none;"
    //                 "color: #AE1818;}");
    MainWindow w;
    w.show();
    return a.exec();
}
