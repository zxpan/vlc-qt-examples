/*
* VLC-Qt QML Player
* Copyright (C) 2015 Tadej Novak <tadej@tano.si>
*/

import QtQuick 2.0
import VLCQt 1.1

Rectangle {
    width: 640
    height: 360
    color: "black"

    VlcPlayer {
        id: player
        logLevel : Vlc.DebugLevel
        url: "https://m4n8c9r5.map2.ssl.hwcdn.net/videos/content/2817383/clip.mp4"
    }
    VlcVideoOutput {
        id: video
        source: player
        anchors.fill: parent
    }
}
