QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# Add qwt path to the project (this will change depending on your build)
QWT_PATH = C:\Qt5\5.12.6\qwt-6.1.4
INCLUDEPATH += $${QWT_PATH}/src
LIBPATH += $${QWT_PATH}/lib

CONFIG(debug, debug|release) { # If debug..
    #DESTDIR = debug
    LIBS += -lqwtd
} else { # If Release..
    #DESTDIR = release
    LIBS += -lqwt
}

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    qwtplothelper.cpp

HEADERS += \
    mainwindow.h \
    qwtplothelper.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
