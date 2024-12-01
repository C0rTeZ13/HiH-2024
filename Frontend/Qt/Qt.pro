QT       += core gui \
            core network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/Authorization.cpp \
    src/MainWindow.cpp \
    src/Parametrs.cpp \
    src/RecognizeObjects.cpp \
    src/Scene/ImageScene.cpp \

HEADERS += \
    src/Authorization.h \
    src/MainWindow.h \
    src/Parametrs.h \
    src/RecognizeObjects.h \
    src/Scene/ImageScene.h \

FORMS += \
    ui/Authorization.ui \
    ui/MainWindow.ui \
    ui/Parametrs.ui \
    ui/RecognizeObjects.ui

TRANSLATIONS += \
    Qt_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

INCLUDEPATH = \
    ui/         \
    src/        \
    src/Scene   \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc

DISTFILES += \
    resources/folder.png \
    resources/folder_invert.png
