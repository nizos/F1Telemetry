import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles.Desktop 1.0

Item {
    id: item1
    width: 600
    height: 360

    Rectangle {
        id: rectangle
        width: 600
        height: 360
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
            id: label
            color: "#ffffff"
            text: qsTr("Km/h")
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Switch {
            id: switch1
            text: qsTr("Switch")
            checked: true
            autoExclusive: false
        }

        Label {
            id: label1
            color: "#ffffff"
            text: qsTr("Always on top")
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Switch {
            id: switch2
            text: qsTr("Switch")
            checked: true
        }

        Label {
            id: label2
            color: "#ffffff"
            text: qsTr("Opacity")
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Slider {
            id: slider
            width: 300
            to: 0.05
            from: 1
            value: 0.5
        }

        Label {
            id: label3
            color: "#ffffff"
            text: qsTr("Scale")
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Slider {
            id: slider1
            width: 300
            to: 0.1
            from: 1
            value: 0.8
        }
    }

}
