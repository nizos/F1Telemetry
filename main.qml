import QtQuick 2.10
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import TelemetryApp.Classes.Core 1.0

Item {
    id: mainApp
    property double overlayOpacity: 0.5
    property double overlaySize: 0.8
    property bool alwaysOnTop: true
    property bool speedUnitKMH: true

    function setOverlayAlwaysOnTop(alwaysOnTop){
        if(alwaysOnTop === true)
        {
            overlayWindow.flags = (Qt.Window |  Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint);
        }
        else
        {
            overlayWindow.flags = (Qt.Window |  Qt.FramelessWindowHint);
        }
    }

    function setOverlayOpacity(overlayOpacity)
    {
        hudGauge.opacity = overlayOpacity;
    }

    function setOverlaySize(overlaySize)
    {
        hudGauge.scale = overlaySize;
    }

    function setOverlaySpeedUnit(speedUnitKMH)
    {
        if(speedUnitKMH === true)
        {

        }
        else
        {

        }
    }

    // Icons font loader
    FontLoader {
        id: fontAwesome
        source: "qrc:/fonts/fontawesome-webfont.ttf"
    }

    ApplicationWindow {
        id: mainWindow
        objectName: "mainWindow"
        visible: true
        width: 600
        height: 400
        x: 1200
        y: 400
        color: "Transparent"
        title: qsTr("TELEMETRY HUD")
        flags: (Qt.Window |  Qt.FramelessWindowHint);
        onClosing: overlayWindow.close();

        WindowControls {
            id: windowControls
            anchors.top: parent.top
        }

        Rectangle {
            id: windowBackground
            anchors.top: windowControls.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            color: "#2b2b2b"
        }

        Grid {
            id: grid
            x: 0
            y: 0
            width: 478
            height: 242
            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            spacing: 20
            rows: 4
            columns: 2

            Label {
                id: speedUnitsLabel
                color: "#ffffff"
                text: qsTr("Km/h")
                font.pointSize: 20
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Switch {
                id: speedUnitsSwitch
                text: qsTr("Switch")
                checked: speedUnitKMH
                autoExclusive: false
                onCheckedChanged: setOverlaySpeedUnit(checked)
            }

            Label {
                id: overlayAlwaysOnTopLabel
                color: "#ffffff"
                text: qsTr("Always on top")
                font.pointSize: 20
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Switch {
                id: overlayAlwaysOnTopSwitch
                text: qsTr("Switch")
                checked: alwaysOnTop
                onCheckedChanged: setOverlayAlwaysOnTop(checked)
            }

            Label {
                id: overlayOpacityLabel
                color: "#ffffff"
                text: qsTr("Opacity")
                font.pointSize: 20
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Slider {
                id: overlayOpacitySlider
                width: 300
                to: 0.05
                from: 1
                value: overlayOpacity
                onValueChanged: setOverlayOpacity(value)
            }

            Label {
                id: overlaySizeLabel
                color: "#ffffff"
                text: qsTr("Scale")
                font.pointSize: 20
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Slider {
                id: overlaySizeSlider
                width: 300
                to: 0.1
                from: 1
                value: overlaySize
                onValueChanged: setOverlaySize(value)

            }
        }
    }


    Window {
        id: overlayWindow
        objectName: "overlayWindow"
        visible: true
        width: 800
        height: 800
        x: 200
        y: 100
        flags: (Qt.Window |  Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint);
        title: qsTr("TELEMETRY HUD OVERLAY")
        color: "Transparent"
        signal refresh;
        HUDGauge {
            id: hudGauge
            anchors.centerIn: parent
            scale: overlaySize
            opacity: overlayOpacity
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
    }
}
