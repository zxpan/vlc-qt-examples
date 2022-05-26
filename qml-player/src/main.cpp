/*
* VLC-Qt QML Player
* Copyright (C) 2015 Tadej Novak <tadej@tano.si>
*/

#include <QtCore/QCoreApplication>
#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>

#include <VLCQtCore/Common.h>
#include <VLCQtQml/QmlVideoPlayer.h>
#include <VLCQtQml/Qml.h>

#include <iostream>

/*
void VlcVideo::setAspectRatio(const QSize& size)
{
    if (_vlcMediaPlayer && libvlc_media_player_has_vout(_vlcMediaPlayer)) {
        auto size_str = QString("%1:%2").arg(QString::number(size.width()), QString::number(size.height()));
        libvlc_video_set_aspect_ratio(_vlcMediaPlayer, size_str.toUtf8().data());
        VlcError::showErrmsg();
    }
}
*/

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("VLC-Qt QML Player");
    //QCoreApplication::setAttribute(Qt::AA_X11InitThreads);
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
    QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);

    QGuiApplication app(argc, argv);
    std::cout << "applicationDirPath=" << app.applicationDirPath().toStdString() << std::endl;
    VlcCommon::setPluginPath(app.applicationDirPath() + "/plugins");
    //VlcCommon::setPluginPath("/Users/zhengxiangpan/project/vlc-qt/build/src/core/VLCQtCore.framework/Versions/1.2.0/lib/vlc/plugins");
    //VlcQmlVideoPlayer::registerPlugin();
    VlcQml::registerTypes();

    QQuickView quickView;
    quickView.setSource(QUrl(QStringLiteral("qrc:/qml/video.qml")));
    //quickView.setResizeMode(QQuickView::SizeRootObjectToView);
    quickView.setResizeMode(QQuickView::SizeViewToRootObject);
    quickView.show();

    return app.exec();
}
