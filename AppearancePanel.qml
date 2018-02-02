import QtQuick 2.2
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.1

Item {
    id: appearancePanel
    width: 320
    height: 240
    SystemPalette { id: palette }
    clip: true
    property bool appearancePanelUnitsKMHValue: true
    property bool appearancePanelAlwaysOnTopValue: true
    property double appearancePanelOpacityValue: 0.5
    property double appearancePanelScaleValue: 0.8
    signal changedKPHUnit(bool appearancePanelUnitsKMHValue)
    signal changedAlwaysOnTop(bool appearancePanelAlwaysOnTopValue)
    signal changedOpacity(double appearancePanelOpacityValue)
    signal changedScale(double appearancePanelScaleValue)

    Grid {
        id: appearancePanelGrid
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
            id: appearancePanelUnitsSwitchLabel
            color: "#ffffff"
            text: qsTr("Km/h")
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Switch {
            id: appearancePanelUnitsSwitch
            text: qsTr("Switch")
            checked: appearancePanelUnitsKMHValue
            onCheckedChanged:
            {
                appearancePanelUnitsKMHValue = checked;
                changedKPHUnit(appearancePanelUnitsKMHValue);
                console.log("From: AppearancePanel || KMH Unit has changed to: " + appearancePanelUnitsKMHValue);
            }
        }

        Label {
            id: appearancePanelAlwaysOnTopSwitchLabel
            color: "#ffffff"
            text: qsTr("Always on top")
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Switch {
            id: appearancePanelAlwaysOnTopSwitch
            text: qsTr("Switch")
            checked: appearancePanelAlwaysOnTopValue
            onCheckedChanged:
            {
                appearancePanelAlwaysOnTopValue = checked;
                changedAlwaysOnTop(appearancePanelAlwaysOnTopValue);
                console.log("From: AppearancePanel || Always On Top has changed to: " + appearancePanelAlwaysOnTopValue);
            }
        }

        Label {
            id: appearancePanelOpacitySliderLabel
            color: "#ffffff"
            text: qsTr("Opacity")
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Slider {
            id: appearancePanelOpacitySlider
            width: 300
            to: 0.05
            from: 1
            value: appearancePanelOpacityValue
            onValueChanged: {
                appearancePanelOpacityValue = value;
                changedOpacity(appearancePanelOpacityValue);
                console.log("From: AppearancePanel || Opacity has changed to: " + appearancePanelOpacityValue);
            }
        }

        Label {
            id: appearancePanelScaleSliderLabel
            color: "#ffffff"
            text: qsTr("Scale")
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Slider {
            id: appearancePanelScaleSlider
            width: 300
            to: 0.1
            from: 1
            value: appearancePanelScaleValue
            onValueChanged: {
                appearancePanelScaleValue = value;
                changedScale(appearancePanelScaleValue);
                console.log("From: AppearancePanel || Scale has changed to: " + appearancePanelScaleValue);
            }
        }
    }
}


//Rectangle {
//    id: windowBackground
//    anchors.top: windowControls.bottom
//    anchors.left: parent.left
//    anchors.right: parent.right
//    anchors.bottom: parent.bottom
//    color: "#2b2b2b"
//}

//Grid {
//    id: grid
//    x: 0
//    y: 0
//    width: 478
//    height: 242
//    anchors.verticalCenterOffset: 0
//    anchors.horizontalCenterOffset: 0
//    anchors.horizontalCenter: parent.horizontalCenter
//    anchors.verticalCenter: parent.verticalCenter
//    spacing: 20
//    rows: 4
//    columns: 2

//    Label {
//        id: speedUnitsLabel
//        color: "#ffffff"
//        text: qsTr("Km/h")
//        font.pointSize: 20
//        verticalAlignment: Text.AlignVCenter
//        horizontalAlignment: Text.AlignHCenter
//    }

//    Switch {
//        id: speedUnitsSwitch
//        text: qsTr("Switch")
//        checked: speedUnitKMH
//        autoExclusive: false
//        onCheckedChanged: setOverlaySpeedUnit(checked)
//    }

//    Label {
//        id: overlayAlwaysOnTopLabel
//        color: "#ffffff"
//        text: qsTr("Always on top")
//        font.pointSize: 20
//        verticalAlignment: Text.AlignVCenter
//        horizontalAlignment: Text.AlignHCenter
//    }

//    Switch {
//        id: overlayAlwaysOnTopSwitch
//        text: qsTr("Switch")
//        checked: alwaysOnTop
//        onCheckedChanged: setOverlayAlwaysOnTop(checked)
//    }

//    Label {
//        id: overlayOpacityLabel
//        color: "#ffffff"
//        text: qsTr("Opacity")
//        font.pointSize: 20
//        verticalAlignment: Text.AlignVCenter
//        horizontalAlignment: Text.AlignHCenter
//    }

//    Slider {
//        id: overlayOpacitySlider
//        width: 300
//        to: 0.05
//        from: 1
//        value: overlayOpacity
//        onValueChanged: setOverlayOpacity(value)
//    }

//    Label {
//        id: overlaySizeLabel
//        color: "#ffffff"
//        text: qsTr("Scale")
//        font.pointSize: 20
//        verticalAlignment: Text.AlignVCenter
//        horizontalAlignment: Text.AlignHCenter
//    }

//    Slider {
//        id: overlaySizeSlider
//        width: 300
//        to: 0.1
//        from: 1
//        value: overlaySize
//        onValueChanged: setOverlaySize(value)

//    }
//}
