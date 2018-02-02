import QtQuick 2.10
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import TelemetryApp.Classes.Core 1.0
import QtQuick.Layouts 1.3



Rectangle {
    id: overlayWindow
    objectName: "overlayWindow"
    visible: true
    width: 800
    height: 800
    antialiasing: true
    color: "Transparent"
    signal refresh;
    
    //// Customization
    // Gauge: Steering
    property string gaugeSteerGaugeFillColor
    property string gaugeSteerGaugeBorderColor
    property string gaugeSteerGaugeBorderWidth
    property string gaugeSteerGaugeRadius
    property string gaugeSteerGaugeHeight
    property string gaugeSteerGaugeWidth

    // BackGround: Gauge Bottom Background
    property string gaugeBottomBackgroundColor
    property string gaugeBottomBackgroundVisible
    property string gaugeBottomBackgroundOpacity

    // Gauge: Speed
    property string gaugeSpeedGaugeColor
    property string gaugeSpeedGaugeOpacity
    property string gaugeSpeedGaugeInitialColor
    property string gaugeSpeedGaugeFinalColor
    property string gaugeSpeedGaugeMajorTickmarkWidth
    property string gaugeSpeedGaugeMajorTickmarkStepSize
    property string gaugeSpeedGaugeMajorTickmarkColor
    property string gaugeSpeedGaugeMinorTickmarkWidth
    property string gaugeSpeedGaugeMinorTickmarkStepSize
    property string gaugeSpeedGaugeMinorTickmarkColor
    property string gaugeSpeedGaugeStartColor
    property string gaugeSpeedGaugeMidLowColor
    property string gaugeSpeedGaugeMidColor
    property string gaugeSpeedGaugeMidHighColor
    property string gaugeSpeedGaugeEndColor
    property string gaugeSpeedGaugeStartValue
    property string gaugeSpeedGaugeMidLowValue
    property string gaugeSpeedGaugeMidValue
    property string gaugeSpeedGaugeMidHighValue
    property string gaugeSpeedGaugeEndValue

    // ForeGround: Speed Foreground
    property string gaugeSpeedForegroundColor
    property string gaugeSpeedForegroundVisible
    property string gaugeSpeedForegroundOpacity

    // Background: DRS Background
    property string gaugeDRSBackgroundColor
    property string gaugeDRSBackgroundVisible
    property string gaugeDRSBackgroundOpacity

    // Background: DRS Light Background
    property string gaugeDRSLightOnBackgroundColor
    property string gaugeDRSLightOnBackgroundOpacity
    property string gaugeDRSLightOnBackgroundVisible
    property string gaugeDRSLightOffBackgroundColor
    property string gaugeDRSLightOffBackgroundOpacity
    property string gaugeDRSLightOffBackgroundVisible
    property string gaugeDRSLightAvailableBackgroundColor
    property string gaugeDRSLightAvailableBackgroundOpacity
    property string gaugeDRSLightAvailableBackgroundVisible
    property string gaugeDRSLightOnTextColor
    property string gaugeDRSLightOnTextOpacity
    property string gaugeDRSLightOnTextSize
    property string gaugeDRSLightOnTextBold
    property string gaugeDRSLightOnTextVisible
    property string gaugeDRSLightOnTextSpacing
    property string gaugeDRSLightOffTextColor
    property string gaugeDRSLightOffTextOpacity
    property string gaugeDRSLightOffTextSize
    property string gaugeDRSLightOffTextBold
    property string gaugeDRSLightOffTextVisible
    property string gaugeDRSLightOffTextSpacing
    property string gaugeDRSLightAvailableTextColor
    property string gaugeDRSLightAvailableTextOpacity
    property string gaugeDRSLightAvailableTextSize
    property string gaugeDRSLightAvailableTextBold
    property string gaugeDRSLightAvailableTextVisible
    property string gaugeDRSLightAvailableTextSpacing

    // Foreground: DRS Field
    property string gaugeDRSFieldColor
    property string gaugeDRSFieldVisible
    property string gaugeDRSFieldOpacity

    // Background: RPM Field Background
    property string gaugeRPMFieldBackgroundColor
    property string gaugeRPMFieldBackgroundVisible
    property string gaugeRPMFieldBackgroundOpacity

    // Gauge: RPM Gauge
    property string gaugeRPMGaugeColor
    property string gaugeRPMGaugeOpacity
    property string gaugeRPMGaugeVisible
    property string gaugeRPMGaugeStartColor
    property string gaugeRPMGaugeMidLowColor
    property string gaugeRPMGaugeMidColor
    property string gaugeRPMGaugeMidHighColor
    property string gaugeRPMGaugeEndColor
    property string gaugeRPMGaugeStartValue
    property string gaugeRPMGaugeMidLowValue
    property string gaugeRPMGaugeMidValue
    property string gaugeRPMGaugeMidHighValue
    property string gaugeRPMGaugeEndValue

    // Background: Throttle & Brake Background
    property string gaugeThrottleBrakeBackgroundColor
    property string gaugeThrottleBrakeBackgroundVisible
    property string gaugeThrottleBrakeBackgroundOpacity

    // Gauge: Brake Gauge
    property string gaugeBrakeGaugeColor
    property string gaugeBrakeGaugeOpacity
    property string gaugeBrakeGaugeInitialColor
    property string gaugeBrakeGaugeFinalColor
    property string gaugeBrakeGaugeMajorTickmarkWidth
    property string gaugeBrakeGaugeMajorTickmarkStepSize
    property string gaugeBrakeGaugeMajorTickmarkColor
    property string gaugeBrakeGaugeMinorTickmarkWidth
    property string gaugeBrakeGaugeMinorTickmarkStepSize
    property string gaugeBrakeGaugeMinorTickmarkColor
    property string gaugeBrakeGaugeStartColor
    property string gaugeBrakeGaugeMidLowColor
    property string gaugeBrakeGaugeMidColor
    property string gaugeBrakeGaugeMidHighColor
    property string gaugeBrakeGaugeEndColor
    property string gaugeBrakeGaugeStartValue
    property string gaugeBrakeGaugeMidLowValue
    property string gaugeBrakeGaugeMidValue
    property string gaugeBrakeGaugeMidHighValue
    property string gaugeBrakeGaugeEndValue


    // Gauge: Throttle Gauge
    property string gaugeThrottleGaugeColor
    property string gaugeThrottleGaugeOpacity
    property string gaugeThrottleGaugeInitialColor
    property string gaugeThrottleGaugeFinalColor
    property string gaugeThrottleGaugeMajorTickmarkWidth
    property string gaugeThrottleGaugeMajorTickmarkStepSize
    property string gaugeThrottleGaugeMajorTickmarkColor
    property string gaugeThrottleGaugeMinorTickmarkWidth
    property string gaugeThrottleGaugeMinorTickmarkStepSize
    property string gaugeThrottleGaugeMinorTickmarkColor
    property string gaugeThrottleGaugeStartColor
    property string gaugeThrottleGaugeMidLowColor
    property string gaugeThrottleGaugeMidColor
    property string gaugeThrottleGaugeMidHighColor
    property string gaugeThrottleGaugeEndColor
    property string gaugeThrottleGaugeStartValue
    property string gaugeThrottleGaugeMidLowValue
    property string gaugeThrottleGaugeMidValue
    property string gaugeThrottleGaugeMidHighValue
    property string gaugeThrottleGaugeEndValue

    // Background: Throttle & Brake Field
    property string gaugeThrottleBrakeFieldColor
    property string gaugeThrottleBrakeFieldVisible
    property string gaugeThrottleBrakeFieldOpacity

    // Foreground: RPM Foreground
    property string gaugeRPMForegroundColor
    property string gaugeRPMForegroundVisible
    property string gaugeRPMForegroundOpacity

    // Label: DRS Text Label
    property string gaugeDRSTextLabelColor
    property string gaugeDRSTextLabelVisible
    property string gaugeDRSTextLabelOpacity
    property string gaugeDRSTextLabelSize
    property string gaugeDRSTextLabelBold
    property string gaugeDRSTextLabelItalic
    property string gaugeDRSTextLabelUnderline
    property string gaugeDRSTextLabelLetterSpacing
    property string gaugeDRSTextLabelFont
    property string gaugeDRSTextLabelText

    // Text: Speed
    property string gaugeSpeedTextValueColor
    property string gaugeSpeedTextValueVisible
    property string gaugeSpeedTextValueOpacity
    property string gaugeSpeedTextValueSize
    property string gaugeSpeedTextValueBold
    property string gaugeSpeedTextValueItalic
    property string gaugeSpeedTextValueUnderline
    property string gaugeSpeedTextValueLetterSpacing
    property string gaugeSpeedTextValueFont
    property string gaugeSpeedTextValueText

    // Label: Speed
    property string gaugeSpeedTextLabelColor
    property string gaugeSpeedTextLabelVisible
    property string gaugeSpeedTextLabelOpacity
    property string gaugeSpeedTextLabelSize
    property string gaugeSpeedTextLabelBold
    property string gaugeSpeedTextLabelItalic
    property string gaugeSpeedTextLabelUnderline
    property string gaugeSpeedTextLabelLetterSpacing
    property string gaugeSpeedTextLabelFont
    property string gaugeSpeedTextLabelText
    property bool gaugeSpeedTextLabelKMH



    // Label: Lap Nr.
    property string gaugeLapNrLabelColor
    property string gaugeLapNrLabelVisible
    property string gaugeLapNrLabelOpacity
    property string gaugeLapNrLabelSize
    property string gaugeLapNrLabelBold
    property string gaugeLapNrLabelItalic
    property string gaugeLapNrLabelUnderline
    property string gaugeLapNrLabelLetterSpacing
    property string gaugeLapNrLabelFont
    property string gaugeLapNrLabelText

    // Text: Lap Nr.
    property string gaugeLapNrTextColor
    property string gaugeLapNrTextVisible
    property string gaugeLapNrTextOpacity
    property string gaugeLapNrTextSize
    property string gaugeLapNrTextBold
    property string gaugeLapNrTextItalic
    property string gaugeLapNrTextUnderline
    property string gaugeLapNrTextLetterSpacing
    property string gaugeLapNrTextFont
    property string gaugeLapNrTextText


    // Label: Position
    property string gaugePositionLabelColor
    property string gaugePositionLabelVisible
    property string gaugePositionLabelOpacity
    property string gaugePositionLabelSize
    property string gaugePositionLabelBold
    property string gaugePositionLabelItalic
    property string gaugePositionLabelUnderline
    property string gaugePositionLabelLetterSpacing
    property string gaugePositionLabelFont
    property string gaugePositionLabelText

    // Text: Position
    property string gaugePositionTextColor
    property string gaugePositionTextVisible
    property string gaugePositionTextOpacity
    property string gaugePositionTextSize
    property string gaugePositionTextBold
    property string gaugePositionTextItalic
    property string gaugePositionTextUnderline
    property string gaugePositionTextLetterSpacing
    property string gaugePositionTextFont
    property string gaugePositionTextText


//    property string speedGaugeColor
//    property string speedGaugeColor
//    property string speedGaugeColor
//    property string speedGaugeColor
//    property string speedGaugeColor
//    property string speedGaugeColor
//    property string speedGaugeColor
//    property string speedGaugeColor
//    property string speedGaugeColor
//    property string speedGaugeColor
//    property string speedGaugeColor
//    property string speedGaugeColor





    // Vehicle
    property int currentIndex: 0

    // Steering
    property double gaugeSteer: 0.000

    // Speed
    property double gaugeSpeed: 0.000
    property int gaugeSpeedValue: 0

    // Throttle
    property double gaugeThrottle: 0.000

    // Brake
    property double gaugeBrake: 0.000

    // Gear
    property int gearValue: 2

    // Rev
    property int currentRev: 0

    // DRS
    property int drsValue: 0
    property int drsAvailable: 0

    // Fuel
    property int currentFuelMix: 1

    // Tyre Temp
    property int tireTempFL: 0
    property int tireTempFR: 0
    property int tireTempRL: 0
    property int tireTempRR: 0

    // Tyre Wear
    property int tireWearFL: 0
    property int tireWearFR: 0
    property int tireWearRL: 0
    property int tireWearRR: 0

    // Lap Nr.
    property int currentLap: 1

    // Lap Times
    property double bestLapTime: 00.0000
    property double lastLapTime: 00.0000
    property double currentLapTime: 00.0000

    // Position
    property int currentPosition

    property int totalLaps
    property double trackSize

    Rectangle {
        id: customWindowFrame
        color: "Transparent"
        antialiasing: true
        anchors.fill: parent
        property QtObject container
        MouseArea {
            id: titleBarMouseRegion
            property var clickPos
            antialiasing: true
            anchors.fill: parent
            onPressed: {
                clickPos = { x: mouse.x, y: mouse.y }
            }
            onPositionChanged: {
                overlayWindow.x = mousePosition.cursorPos().x - clickPos.x
                overlayWindow.y = mousePosition.cursorPos().y - clickPos.y
            }
        }
    }

    function getNewData() // Function: Get New Telemetry Data
    {

        gaugeSteer = telemetry.getSteer();
        gaugeSpeed = telemetry.getSpeedInKPH();
        gaugeThrottle = telemetry.getThrottle();
        gaugeBrake = telemetry.getBrake();
        gearValue = telemetry.getGear();
        drsValue = telemetry.getDRS();
        currentRev = telemetry.getRevLightsPercent();

        tireTempFL = telemetry.getTyresTemperatureFrontLeft();
        tireTempFR = telemetry.getTyresTemperatureFrontRight();
        tireTempRL = telemetry.getTyresTemperatureRearLeft();
        tireTempRR = telemetry.getTyresTemperatureRearRight();

        tireWearFL = telemetry.getTyresWearFrontLeft();
        tireWearFR = telemetry.getTyresWearFrontRight()
        tireWearRL = telemetry.getTyresWearRearLeft();
        tireWearRR = telemetry.getTyresWearRearRight();

        drsAvailable = telemetry.getDRSAllowed();
        currentFuelMix = telemetry.getFuelMix();
        currentLap = telemetry.getLap();

        currentIndex = telemetry.getPlayerCarIndex();
        bestLapTime = telemetry.getBestLapTimeForCar(currentIndex);
        lastLapTime = telemetry.getLastLapTime();
        currentLapTime = telemetry.getLapTime();
        currentPosition = telemetry.getCarPosition();

        overlayWindow.refresh();
    }

    function timeFormatter(timeInSeconds) // Function: Convert Seconds to Minutes, Seconds & Milli Seconds
    {
        var formattedTime = new Date(timeInSeconds*1000);
        return Qt.formatTime(formattedTime,"mm:ss.zzz");
    }

    Timer // Timer: Data Refresh Timer
    {
        id: overlayTimer
        interval: 20; running: true; repeat: true
        onTriggered: overlayWindow.getNewData();
    }



    Rectangle // Background: Main Window Background
    {
        id: background
        color: "Transparent"
        antialiasing: true
        //        color: "#000000"
        anchors.fill: parent
    }

    CircularGauge // Gauge: Steering
    {
        id: circularGaugeSteer
        x: 87
        y: 101
        width: 700
        height: 700
        antialiasing: true
        value: overlayWindow.gaugeSteer
        minimumValue: -1
        maximumValue: 1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        style: CircularGaugeStyle
        {
            function degreesToRadians(degrees)
            {
                return degrees * (Math.PI / 180);
            }
            tickmark: Rectangle
            {

            }
            minorTickmark: Rectangle
            {

            }
            maximumValueAngle: -135
            minimumValueAngle: 135
            tickmarkStepSize: 1
            tickmarkLabel: Text
            {

            }
            needle: Rectangle
            {
                y: outerRadius * 0.15
                implicitWidth: outerRadius * 0.2
                implicitHeight: outerRadius * 1.2
                antialiasing: true
                color: "#19b5fe"
                border.color: "#3a3a3a"
                border.width: 3
                radius: 40
            }
            foreground: Item
            {

            }
        }
    }



    Image // BackGround: Gauge Bottom Background
    {
        id: f1GaugeBottomBackground
        width: 800
        height: 800
        antialiasing: true
        fillMode: Image.PreserveAspectFit
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/images/F1GaugeBottomBackground.png"
    }

    CircularGauge // Gauge: Speed
    {
        id: circularGaugeSpeed
        x: 87
        y: 101
        width: 627
        height: 600
        antialiasing: true
        maximumValue: 360
        value: overlayWindow.gaugeSpeed
        style: CircularGaugeStyle
        {
            function degreesToRadians(degrees)
            {
                return degrees * (Math.PI / 180);
            }

            tickmark: Rectangle
            {
                implicitWidth: outerRadius * 0.005
                antialiasing: true
                implicitHeight: outerRadius * 0.14
                color: "#ABB7B7"
            }
            minorTickmark: Rectangle
            {
                implicitWidth: 0
                antialiasing: true
                implicitHeight: 0
                color: "#ABB7B7"
            }
            maximumValueAngle: 135
            minimumValueAngle: -135
            tickmarkStepSize: 10
            tickmarkLabel: Text
            {

            }
            needle: Rectangle
            {

            }
            foreground: Item
            {

            }
            background: Canvas
            {
                id: speedCanvas
                onPaint: {
                    var ctx = getContext("2d");
                    ctx.reset();
                    ctx.beginPath();
                    ctx.strokeStyle = "#19B5FE";
                    ctx.lineWidth = outerRadius * 0.14;
                    ctx.arc(outerRadius, outerRadius, outerRadius - ctx.lineWidth / 2,
                            degreesToRadians(valueToAngle(0) - 90), degreesToRadians(valueToAngle(overlayWindow.gaugeSpeed) - 90));
                    ctx.stroke();
                }

                Connections
                {
                    target: overlayWindow
                    onRefresh: speedCanvas.requestPaint();
                }
            }
        }
    }

    Image // ForeGround: Speed Foreground
    {
        id: f1GaugeSpeedField
        width: 800
        height: 800
        antialiasing: true
        fillMode: Image.PreserveAspectFit
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/images/F1GaugeSpeedField.png"
    }

    Image // Background: DRS Background
    {
        id: f1GaugeDRSBackground
        width: 800
        height: 800
        antialiasing: true
        fillMode: Image.PreserveAspectFit
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/images/F1GaugeDRSBackground.png"
    }

    Rectangle // Background: DRS Light Background
    {
        id: f1GaugeDRSLight
        width: 400
        height: 400
        color: drsColorFinder();
        radius: 200
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        function drsColorFinder() // Function: Provides DRS Light Color for DRS Values
        {
            var drsColor = "Transparent"
            if(overlayWindow.drsValue === 1)
            {
                drsColor = "Green"
            }
            else if(overlayWindow.drsAvailable === 1 && overlayWindow.drsValue === 0)
            {
                drsColor = "Yellow"
            }
            return drsColor;
        }
    }

    Image // Foreground: DRS Field
    {
        id: f1GaugeDRSField
        width: 800
        height: 800
        antialiasing: true
        fillMode: Image.PreserveAspectFit
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/images/F1GaugeDRSField.png"
    }

    Image // Background: RPM Field Background
    {
        id: rpmFieldBackground
        width: 800
        height: 800
        antialiasing: true
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/images/F1GaugeRPMFieldBackground.png"
    }

    Gauge // Gauge: RPM Gauge
    {
        id: rpmGauge
        x: 378
        y: 309
        width: 40
        height: 370
        anchors.verticalCenterOffset: -110
        anchors.horizontalCenterOffset: 1
        antialiasing: true
        rotation: 90
        value: overlayWindow.currentRev
        minimumValue: 0
        maximumValue: 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        style: GaugeStyle
        {
            function rpmGaugeColor()
            {
                if(rpmGauge.value < 50)
                {
                    return Qt.rgba(0, 1, 0, 1)
                }
                if(rpmGauge.value >= 50 && rpmGauge.value < 60)
                {
                    var orangeMinRPMValue = 50;
                    return Qt.rgba( (rpmGauge.value - orangeMinRPMValue)/ 10, (orangeMinRPMValue) / orangeMinRPMValue, 0, 1)
                }
                if(rpmGauge.value >= 60 && rpmGauge.value < 70)
                {
                    var redMinRPMValue = 60;
                    return Qt.rgba( redMinRPMValue/ redMinRPMValue, 1 - (rpmGauge.value - redMinRPMValue) / 10, 0, 1)
                }
                else if(rpmGauge.value >= 70 && rpmGauge.value < 80)
                {
                    var blueMinRPMValue = 70;
                    return Qt.rgba(1 - (rpmGauge.value - blueMinRPMValue) /10, 0, (rpmGauge.value - blueMinRPMValue) / 10, 1)
                }
                else if(rpmGauge.value >= 80)
                {
                    return Qt.rgba(0, 0, 1, 1)
                }
                else{
                    return Qt.rgba(0, 1, 0, 1)
                }
            }
            valueBar: Rectangle
            {
                implicitWidth: 30
                color: rpmGaugeColor();
            }
            minorTickmark: Item
            {
                Rectangle
                {

                }
            }
            tickmark: Item
            {
                Rectangle
                {

                }
            }
            tickmarkLabel: Item
            {
                Rectangle
                {

                }
            }
        }
    }

    Image // Background: Throttle & Brake Background
    {
        id: f1GaugeThrottleBrakeBackground
        width: 800
        height: 800
        antialiasing: true
        fillMode: Image.PreserveAspectFit
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/images/F1GaugeThrottleBrakeFieldBackground.png"
    }

    CircularGauge // Gauge: Brake Gauge
    {
        id: circularGaugeBrake
        x: 159
        y: 161
        width: 500
        height: 500
        antialiasing: true
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        maximumValue: 1
        value: overlayWindow.gaugeBrake
        style: CircularGaugeStyle
        {
            function degreesToRadians(degrees)
            {
                return degrees * (Math.PI / 180);
            }
            maximumValueAngle: 47
            minimumValueAngle: 136
            tickmarkStepSize: 0.1
            tickmark: Rectangle
            {
                implicitWidth: outerRadius * 0.005
                antialiasing: true
                implicitHeight: outerRadius * 0.18
                color: "#ABB7B7"
            }
            minorTickmark: Rectangle
            {
                implicitWidth: 0
                antialiasing: true
                implicitHeight: 0
                color: "#ABB7B7"
            }
            tickmarkLabel: Text
            {

            }
            needle: Rectangle
            {

            }
            foreground: Item
            {

            }
            background: Canvas
            {
                id: brakeCanvas
                onPaint:
                {
                    var ctx = getContext("2d");
                    ctx.reset();
                    ctx.beginPath();
                    ctx.strokeStyle = "#DC3023";
                    ctx.lineWidth = outerRadius * 0.18;
                    ctx.arc(outerRadius, outerRadius, outerRadius - ctx.lineWidth / 2,
                            degreesToRadians(valueToAngle(overlayWindow.gaugeBrake) - 90), degreesToRadians(valueToAngle(0) - 90));
                    ctx.stroke();
                }

                Connections
                {
                    target: overlayWindow
                    onRefresh: brakeCanvas.requestPaint();
                }
            }
        }
    }

    CircularGauge // Gauge: Throttle Gauge
    {
        id: circularGaugeThrottle
        x: 128
        y: 154
        width: 500
        height: 500
        antialiasing: true
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        stepSize: 0
        maximumValue: 1
        value: overlayWindow.gaugeThrottle
        style: CircularGaugeStyle
        {
            function degreesToRadians(degrees)
            {
                return degrees * (Math.PI / 180);
            }
            tickmarkStepSize: 0.05
            tickmark: Rectangle
            {
                implicitWidth: outerRadius * 0.005
                antialiasing: true
                implicitHeight: outerRadius * 0.18
                color: "#ABB7B7"
            }
            minorTickmark: Rectangle
            {
                implicitWidth: 0
                antialiasing: true
                implicitHeight: 0
                color: "#ABB7B7"
            }
            maximumValueAngle: 44
            minimumValueAngle: -136
            tickmarkLabel: Text
            {

            }
            needle: Rectangle
            {

            }
            foreground: Item
            {

            }
            background: Canvas
            {
                id: throttleCanvas
                onPaint:
                {
                    var ctx = getContext("2d");
                    ctx.reset();
                    ctx.beginPath();
                    ctx.strokeStyle = "#26A65B";
                    ctx.lineWidth = outerRadius * 0.18;
                    ctx.arc(outerRadius, outerRadius, outerRadius - ctx.lineWidth / 2,
                            degreesToRadians(valueToAngle(0) - 90), degreesToRadians(valueToAngle(overlayWindow.gaugeThrottle) - 90));
                    ctx.stroke();
                }

                Connections
                {
                    target: overlayWindow
                    onRefresh: throttleCanvas.requestPaint();
                }
            }
        }
    }

    Image // Background: Throttle & Brake Field
    {
        id: f1GaugeThrottleBrakeField
        width: 800
        height: 800
        antialiasing: true
        fillMode: Image.PreserveAspectFit
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/images/F1GaugeThrottleBrakeField.png"
    }

    Image // Foreground: RPM Foreground
    {
        id: rpmForeground
        width: 800
        height: 800
        antialiasing: true
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/images/F1GaugeRPMForeground.png"
    }

    Text // Label: DRS Text Label
    {
        id: drsTextValue
        x: 357
        y: 213
        color: "#ffffff"
        text: qsTr("DRS")
        font.pixelSize: 46
    }

    Text // Text: Speed
    {
        id: speedValue
        x: 343
        y: 608
        width: 115
        height: 26
        color: "#19b5fe"
        text: overlayWindow.gaugeSpeed.toFixed(0);
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize:80
    }

    Text // Label: Speed
    {
        id: speedLabel
        x: 343
        y: 660
        width: 115
        height: 41
        color: "#828282"
        text: qsTr("km/h")
        font.letterSpacing: 5
        font.capitalization: Font.AllUppercase
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 30
    }

    Grid // Grid: Lap times
    {
        id: timeGrid
        x: 305
        y: 359
        width: 221
        height: 109
        antialiasing: true
        clip: true
        rows: 3
        columns: 2
        spacing: 5

        Text // Label: Best Lap Time
        {
            id: bestTimeLabel
            width: 65
            color: "#9e9c9c"
            text: qsTr("Best:")
            font.capitalization: Font.AllUppercase
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 24
        }


        Text // Text: Best Lap Time
        {
            id: bestTimeValue
            width: 100
            color: "#ffffff"
            text: overlayWindow.timeFormatter(overlayWindow.bestLapTime)
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 24

        }


        Text // Label: Last Lap Time
        {
            id: lastTimeLabel
            width: 65
            color: "#9e9c9c"
            text: qsTr("Last:")
            font.capitalization: Font.AllUppercase
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 24
        }


        Text // Text: Last Lap Time
        {
            id: lastTimeValue
            width: 100
            color: "#ffffff"
            text: overlayWindow.timeFormatter(overlayWindow.lastLapTime)
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 24
        }


        Text // Label: Current Lap Time
        {
            id: currentLapLabel
            width: 65
            color: "#9e9c9c"
            text: qsTr("TIME:")
            font.capitalization: Font.AllUppercase
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 24
        }


        Text // Text: Current Lap Time
        {
            id: currentLapValue
            color: "#ffffff"
            text: overlayWindow.timeFormatter(overlayWindow.currentLapTime)
            font.pixelSize: 24
        }
    }

    Grid // Tyre Temps Grid
    {
        id: tyreTempGrid
        x: 510
        y: 359
        width: 76
        height: 100
        antialiasing: true
        spacing: 12
        rows: 2
        columns: 2

        function tireTempColor(temp) // Function: Provide Color Value For Temp Value
        {
            if(temp < 50) // Blue
            {
                return Qt.rgba(0, 0, 1, 1)
            }
            if(temp >= 50 && temp < 75) // Blue to Green
            {
                var blueTempValue = 50;
                return Qt.rgba(0, (temp - blueTempValue) / 25, 1 - (temp - blueTempValue) / 25, 1)
            }
            if(temp >= 75 && temp < 100)
            { // Green to Orange
                var greenTempValue = 75;
                return Qt.rgba( (temp - greenTempValue) / 25, greenTempValue / greenTempValue, 0, 1)
            }
            if(temp >= 100)
            { // Orange to Red
                var orangeTempValue = 100;
                return Qt.rgba( orangeTempValue/ orangeTempValue, 1 - (temp - orangeTempValue) / 20, 0, 1)
            }
            else
            {
                return Qt.rgba(0, 1, 0, 1)
            }
        }

        Rectangle // Front Left
        {
            id: tempTireFL
            width: 30
            height: 40
            color: tyreTempGrid.tireTempColor(overlayWindow.tireTempFL)
            radius: 5
            border.color: "#e2e2e2"
        }

        Rectangle // Front Right
        {
            id: tempTireFR
            width: 30
            height: 40
            color: tyreTempGrid.tireTempColor(overlayWindow.tireTempFR)
            radius: 5
            border.color: "#e2e2e2"
        }


        Rectangle // Rear Left
        {
            id: tempTireRL
            width: 30
            height: 40
            color: tyreTempGrid.tireTempColor(overlayWindow.tireTempRL)
            radius: 5
            border.color: "#e2e2e2"
        }

        Rectangle // Rear Right
        {
            id: tempTireRR
            width: 30
            height: 40
            color: tyreTempGrid.tireTempColor(overlayWindow.tireTempRR)
            radius: 5
            border.color: "#e2e2e2"
        }
    }

    ListView // View: Gear List View
    {
        id: gearsListView
        width: 300
        height: 86
        antialiasing: true
        clip: true
        anchors.verticalCenterOffset: 108
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 5
        model: gearsModel
        currentIndex: overlayWindow.gearValue
        orientation: Qt.Horizontal
        preferredHighlightBegin: 150 - 15
        preferredHighlightEnd: 150 + 15
        highlightRangeMode: ListView.StrictlyEnforceRange
        delegate: Rectangle // Rectangle: Gear Nr.
        {
            width: 50
            color: "Transparent"
            height: ListView.view.height

            Text // Text: Gear Nr.
            {
                property int currI: gearsListView.currentIndex
                anchors.centerIn: parent
                text: gear
                font.pixelSize: currI === index ? 80 : 60 - (Math.abs(currI - index) * 20)
                color: determineColor(index)
            }

            function determineColor(index) // Function: Provide Color Value for Gear Nr.
            {
                if(index === 0 && index === overlayWindow.gearValue)
                {
                    return "red";
                }
                else if(index === 1 && index === overlayWindow.gearValue)
                {
                    return "orange";
                }
                else
                {
                    return "white";
                }
            }
        }
    }

    ListModel // Model: Gear List Model
    {
        id: gearsModel
        ListElement
        {
            index: 0
            gear: "R"
        }
        ListElement
        {
            index: 1
            gear: "N"
            color: "Orange"
        }
        ListElement
        {
            index: 2
            gear: "1"
        }
        ListElement
        {
            index: 3
            gear: "2"
        }
        ListElement
        {
            index: 4
            gear: "3"
        }
        ListElement
        {
            index: 5
            gear: "4"
        }
        ListElement
        {
            index: 6
            gear: "5"
        }
        ListElement
        {
            index: 7
            gear: "6"
        }
        ListElement
        {
            index: 8
            gear: "7"
        }
        ListElement
        {
            index: 9
            gear: "8"
        }
    }


    Text {
        id: currentFuelMixLabel
        x: 328
        y: 316
        width: 69
        height: 46
        text: qsTr("FUEL: ")
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 24
    }

    Text // Text: Fuel Mix
    {
        id: currentFuelMixValue
        x: 398
        y: 316
        width: 170
        height: 46
        color: fuelMixColor();
        text: fuelMixText();
        textFormat: Text.AutoText
        font.weight: Font.DemiBold
        font.capitalization: Font.AllUppercase
        font.family: "MS Shell Dlg 2"
        font.bold: false
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 24

        function fuelMixText() // Function: Provide Text String for Fuel Mix Value
        {
            var mix = "MIXED"
            if(overlayWindow.currentFuelMix === 0)
            {
                mix = "LEAN"
            }
            else if(overlayWindow.currentFuelMix === 1)
            {
                mix = "STANDARD"
            }
            else if(overlayWindow.currentFuelMix === 2)
            {
                mix = "RICH"
            }
            return mix;
        }

        function fuelMixColor() // Function: Provide Text Color for Fuel Mix Value
        {
            var colorValue = "Green"
            if(overlayWindow.currentFuelMix === 0)
            {
                colorValue = "Blue"
            }
            else if(overlayWindow.currentFuelMix === 1)
            {
                colorValue = "Green"
            }
            else if(overlayWindow.currentFuelMix === 2)
            {
                colorValue = "#f5680e"
            }
            return colorValue;
        }

    }



    Grid // Grid: Tyre Wear
    {
        id: tyreWearGrid
        x: 216
        y: 359
        width: 76
        height: 100
        antialiasing: true
        spacing: 12
        columns: 2
        rows: 2

        Rectangle // Front Left
        {
            id: tireWearFLRectangle
            width: 30
            height: 40
            color: "#2d2d2d"
            radius: 5
            border.color: "#e2e2e2"

            Text // Text: Front Left
            {
                id: tireWearFLValue
                color: "#ffffff"
                text: overlayWindow.tireWearFL
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 22
            }
        }

        Rectangle // Front Right
        {
            id: tireWearFRRectangle
            width: 30
            height: 40
            color: "#2d2d2d"
            radius: 5
            border.color: "#e2e2e2"

            Text  // Text: Front Right
            {
                id: tireWearFRValue
                color: "#ffffff"
                text: overlayWindow.tireWearFR
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 22
            }
        }

        Rectangle // Rear Left
        {
            id: tireWearRLRectangle
            width: 30
            height: 40
            color: "#2d2d2d"
            radius: 5
            border.color: "#e2e2e2"

            Text  // Text: Rear Left
            {
                id: tireWearRLValue
                color: "#ffffff"
                text: overlayWindow.tireWearRL
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 22
            }
        }

        Rectangle  // Rear Right
        {
            id: tireWearRRRectangle
            width: 30
            height: 40
            color: "#2d2d2d"
            radius: 5
            border.color: "#e2e2e2"

            Text  // Text: Rear Right
            {
                id: tireWearRRValue
                color: "#ffffff"
                text: overlayWindow.tireWearRR
                font.family: "MS Shell Dlg 2"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 22
            }
        }
    }


    Text // Text: Lap Nr.
    {
        id: currentLapNrTextValue
        x: 250
        y: 588
        width: 66
        height: 38
        color: "#ffffff"
        text: (overlayWindow.currentLap+1)
        font.capitalization: Font.AllUppercase
        font.bold: false
        font.weight: Font.DemiBold
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 62
    }


    Text // Label: Lap Nr.
    {
        id: currentLapNrTextLabel
        x: 259
        y: 637
        width: 48
        height: 27
        color: "#828282"
        text: qsTr("LAP")
        font.letterSpacing: 5
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 20
    }

    Text {
        id: currentPositionTextValue
        x: 493
        y: 570
        width: 57
        height: 75
        color: "#ffffff"
        text: overlayWindow.currentPosition
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.weight: Font.DemiBold
        font.pixelSize: 60
    }

    Text {
        id: currentPositionTextLabel
        x: 498
        y: 637
        width: 48
        height: 27
        color: "#828282"
        text: qsTr("POS")
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 20
        font.letterSpacing: 5
        horizontalAlignment: Text.AlignHCenter
    }


}
