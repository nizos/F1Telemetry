import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    height: 300

    Rectangle {
        id: background
        x: 0
        y: 0
        width: 640
        height: 300
        color: "#000000"

        Slider {
            id: slider
            x: 200
            y: 95
            rotation: 180
            spacing: 0
            wheelEnabled: false
            to: 100
            from: 1000
            value: 800
        }


    }

}
