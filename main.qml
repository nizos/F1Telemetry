import QtQuick 2.10
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import TelemetryApp.Classes.Core 1.0
import 'qrc:/Windows/'

Item {
    id: mainApp
    property double overlayOpacity: 0.5
    property double overlayScale: 0.8
    property bool overlayAlwaysOnTop: true
    property bool overlaySpeedUnits: true
    signal overlayChangedOpacity(double overlayOpacity)
    signal overlayChangedScale(double overlayScale)

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
        overlayWindow.opacity = overlayOpacity;
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


    ControlsWindow {
        objectName: "controlsWindow"
        id: controlsWindow
    }

    OverlayWindow {
        objectName: "overlayWindow"
        id: overlayWindow
    }

    Connections {
        target: controlsWindow
        onWindowClose: overlayWindow.close()
        onOverlayChangedSpeedUnit:
        {
            mainApp.overlaySpeedUnits = overlayUnitsInKPH;
            console.log("From MainApp || Speed Units changed: " + mainApp.overlaySpeedUnits);
        }
        onOverlayChangedAlwaysOnTop:
        {
            mainApp.overlayAlwaysOnTop = overlayAlwaysOnTop;
            console.log("From MainApp || Always On Top changed: " + mainApp.overlayAlwaysOnTop);
        }
        onOverlayChangedOpacity:
        {
            mainApp.overlayOpacity = overlayOpacity;
            overlayChangedOpacity(mainApp.overlayOpacity);
            console.log("From MainApp || Opacity changed: " + mainApp.overlayOpacity);
        }
        onOverlayChangedScale:
        {
            mainApp.overlayScale = overlayScale;
            overlayChangedScale(mainApp.overlayScale);
            console.log("From MainApp || Scale changed: " + mainApp.overlayScale);
        }
    }

}
