import QtQuick 2.10
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import TelemetryApp.Classes.Core 1.0
import 'qrc:/overlays/'

Window {
    id: overlayWindow
    visible: true
    height: 800
    width: 800
    x: 200
    y: 100
    flags: (Qt.Window |  Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint);
    modality: Qt.NonModal
    title: qsTr("TELEMETRY HUD OVERLAY")
    color: "Transparent"
    opacity: overlayWindow.overlayOpacity
    property double overlayOpacity: 0.8
    property double overlayScale: 0.8
    signal refresh;
    HUDGauge {
        id: hudGauge
        anchors.centerIn: parent
        scale: overlayWindow.overlayScale
    }
    property QtObject container
    MouseArea {
        id: titleBarMouseRegion
        property var clickPos
        anchors.fill: hudGauge
        onPressed: {
            clickPos = { x: mouse.x, y: mouse.y }
        }
        onPositionChanged: {
            overlayWindow.x = mousePosition.cursorPos().x - clickPos.x
            overlayWindow.y = mousePosition.cursorPos().y - clickPos.y
        }
    }

    Connections {
        target: mainApp
        onOverlayChangedOpacity: overlayWindow.overlayOpacity = overlayOpacity;
        onOverlayChangedScale: overlayWindow.overlayScale = overlayScale;
    }


}
