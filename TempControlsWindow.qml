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
    property bool unitsInKMH: true

    TabView {
        id: tabView
        anchors.fill: parent

        Tab {
            id: appearanceTab
            title: "Appearance"
            AppearancePanel {
            }
        }

        Tab {
            title: "Customization"
            CustomizationPanel {
                id: customizationPanel
            }
        }

        Tab {
            title: "About"
            activeFocusOnTab: false
            active: true
            AboutPanel {
                id: aboutPanel
            }
        }
    }

    Connections {
        target: appearanceTab.item
        onChangedKPHUnit:
        {
            controlsWindow.unitsInKMH = appearancePanelUnitsKMHValue;
            console.log("KMH Unit has changed to: " + controlsWindow.unitsInKMH);
        }
    }
}
