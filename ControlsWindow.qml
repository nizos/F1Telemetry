import QtQuick 2.10
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls 2.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import TelemetryApp.Classes.Core 1.0
import 'qrc:/panels/'
import 'qrc:/elements/'

ApplicationWindow {
    id: controlsWindow
    objectName: "controlsWindow"
    width: 580
    height: 480
    visible: true
    color: "Transparent"
    title: qsTr("TELEMETRY HUD")
    flags: (Qt.Window |  Qt.FramelessWindowHint);
    property bool overlayUnitsInKPH
    property bool overlayAlwaysOnTop
    property double overlayOpacity
    property double overlayScale
    signal overlayChangedSpeedUnit(bool overlayUnitsInKPH)
    signal overlayChangedAlwaysOnTop(bool overlayAlwaysOnTop)
    signal overlayChangedOpacity(double overlayOpacity)
    signal overlayChangedScale(double overlayScale)
    signal windowClose
    onClosing: windowClose()

    TitleBar {
        id: titleBar
        anchors.top: parent.top
    }

    TabBar {
        id: controlsWindowTabBar
        width: parent.width
        anchors.top: titleBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 0
        anchors.rightMargin: 0
        anchors.leftMargin: 0

        TabButton {
            id: appearancePanelTabButton
            text: qsTr("Appearance")
            onClicked: tabView.currentIndex = 0
        }

        TabButton {
            id: customizationPanelTabButton
            text: qsTr("Customization")
            onClicked: tabView.currentIndex = 1
        }

        TabButton {
            id: unitsPanelTabButton
            text: qsTr("Units")
            onClicked: tabView.currentIndex = 2
        }
        TabButton {
            id: userPanelTabButton
            text: qsTr("User")
            onClicked: tabView.currentIndex = 3
        }
        TabButton {
            id: aboutPanelTabButton
            text: qsTr("About")
            onClicked: tabView.currentIndex = 4
        }
    }

    TabView {
        id: tabView
        tabsVisible: false
        anchors.top: controlsWindowTabBar.bottom
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        Tab {
            id: appearancePanel
            AppearancePanel {
            }
        }
        Tab {
            id: customizationPanel
            CustomizationPanel { }
        }
        Tab {
            id: userPanelTab
            UserPanel { anchors.fill: parent }
        }
        Tab {
            id: unitsPanelTab
            UnitsPanel { anchors.fill:parent }
        }
        Tab {
            id: aboutPanelTab
            AboutPanel { anchors.fill:parent }
        }
    }

    Connections {
        target: titleBar
        onWindowClose: {
            windowClose();
            controlsWindow.close();
        }
    }

    Connections {
        target: appearancePanel.item
        onChangedKPHUnit:
        {
            controlsWindow.overlayUnitsInKPH = appearancePanelUnitsKMHValue;
            overlayChangedSpeedUnit(overlayUnitsInKPH);
        console.log("From: Controls Window || KMH Unit has changed to: " + controlsWindow.overlayUnitsInKPH);
        }
        onChangedAlwaysOnTop:
        {
            controlsWindow.overlayAlwaysOnTop = appearancePanelAlwaysOnTopValue;
            overlayChangedAlwaysOnTop(overlayAlwaysOnTop);
            console.log("From: Controls Window || Always On Top has changed to: " + controlsWindow.overlayAlwaysOnTop);
        }
        onChangedOpacity:
        {
            controlsWindow.overlayOpacity = appearancePanelOpacityValue;
            overlayChangedOpacity(overlayOpacity);
            console.log("From: Controls Window || Opacity has changed to: " + controlsWindow.overlayOpacity);
        }
        onChangedScale: {
            controlsWindow.overlayScale = appearancePanelScaleValue;
            overlayChangedScale(overlayScale);
            console.log("From: Controls Window || Scale has changed to: " + controlsWindow.overlayScale);
        }
    }
}















