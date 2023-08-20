QT       += core gui\
            sql\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -fopenmp
QMAKE_LFLAGS += -fopenmp
LIBS += -fopenmp -lgomp

SOURCES += \
    detectpicture.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp\
    md5.cpp \
    registerwindow.cpp \
    sqliteoperator.cpp\
    client.cpp\
    yolo.cpp \
    theme.cpp \
    model_choose.cpp \
    user_manage.cpp

HEADERS += \
    detectpicture.h \
    loginwindow.h \
    mainwindow.h\
    md5.h \
    registerwindow.h \
    sqliteoperator.h\
#    client.h\/
    yolo.h \
    theme.h \
    model_choose.h \
    user_manage.h

FORMS += \
    loginwindow.ui \
    mainwindow.ui \
    registerwindow.ui \
    theme.ui \
    model_choose.ui \
    user_manage.ui \
    review.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# opencv ncnn
INCLUDEPATH += $$PWD/lib/opencv/opencv4 \
               $$PWD/lib/opencv/opencv4/opencv2 \
               $$PWD/lib/ncnn/include \
               $$PWD/lib/vsoa/include/libvsoa \
               $$PWD/lib/vsoa/include/libcjson

LIBS += $$PWD/lib/opencv/libopencv_highgui.so \
        $$PWD/lib/opencv/libopencv_core.so    \
        $$PWD/lib/opencv/libopencv_imgproc.so \
        $$PWD/lib/opencv/libopencv_imgcodecs.so \
        $$PWD/lib/opencv/libopencv_videoio.so\
        $$PWD/lib/ncnn/libncnn.a \
        $$PWD/lib/vsoa/lib/libvsoa-cjson.so \
        $$PWD/lib/vsoa/lib/libvsoa-parser.so \
        $$PWD/lib/vsoa/lib/libvsoa-client.so \
        $$PWD/lib/vsoa/lib/libvsoa-server.so \
        $$PWD/lib/vsoa/lib/libvsoa-position.so

RESOURCES += \
    forqss.qrc





