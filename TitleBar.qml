import QtQuick 2.10
import QtQuick.Window 2.2

Rectangle {
    id: titleBar
    color: "#003459"
    height: 30
    anchors.top: parent.top
    anchors.left: parent.left
    anchors.right: parent.right
    radius: 5
    signal windowClose
    signal windowMinimize
    signal windowRestore
    property QtObject container

    // Icons font loader
    FontLoader {
        id: fontAwesome
        source: "qrc:/fonts/fontawesome-webfont.ttf"
    }

    MouseArea {
        id: titleBarMouseRegion
        property var clickPos
        anchors.fill: parent
        onPressed: {
            clickPos = { x: mouse.x, y: mouse.y }
        }
        onPositionChanged: {
            controlsWindow.x = mousePosition.cursorPos().x - clickPos.x
            controlsWindow.y = mousePosition.cursorPos().y - clickPos.y
        }
    }

    Rectangle {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        color: "#003459"
        height: 10
    }

    Rectangle {
        id: closeWindowButton
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.topMargin: 2
        anchors.rightMargin: 5
        anchors.bottomMargin: 2
        color: "transparent"
        width: 18

        Text {
            id: closeWindowButtonIcon
            text: "\uf2d3"
            color: "#c4c4c4"
            font.pointSize: 14
            font.family: fontAwesome.name
            anchors.centerIn: parent
        }
        MouseArea {
            id: closeWindowButtonMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: closeWindowButtonIcon.color = "#FFFFFF";
            onExited: closeWindowButtonIcon.color = "#c4c4c4";
            onClicked: windowClose()
        }
    }

    Rectangle {
        id: resizeWindowButton
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: closeWindowButton.left
        anchors.topMargin: 2
        anchors.rightMargin: 10
        anchors.bottomMargin: 2
        color: "transparent"
        width: 18
        Text {
            id: resizeWindowButtonIcon
            text: "\uf2d0"
            color: "#c4c4c4"
            font.pointSize: 14
            font.family: fontAwesome.name
            anchors.centerIn: parent
        }
        MouseArea {
            id: resizeWindowButtonMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: resizeWindowButtonIcon.color = "#FFFFFF";
            onExited: resizeWindowButtonIcon.color = "#c4c4c4";
            onClicked: windowRestore()
        }
    }
    Rectangle {
        id: minimizeWindowButton
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: resizeWindowButton.left
        anchors.topMargin: 2
        anchors.rightMargin: 10
        anchors.bottomMargin: 2
        color: "transparent"
        width: 18
        Text {
            id: minimizeWindowButtonIcon
            text: "\uf2d1"
            color: "#c4c4c4"
            font.pointSize: 14
            font.family: fontAwesome.name
            anchors.centerIn: parent
        }
        MouseArea {
            id: minimizeWindowButtonMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onClicked: windowMinimize()
            onEntered: minimizeWindowButtonIcon.color = "#FFFFFF";
            onExited: minimizeWindowButtonIcon.color = "#c4c4c4";
        }
    }
}
