import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Text {
        id: text1
        x: 101
        y: 264
        text: qsTr("Temperature")
        font.pixelSize: 24
    }

    ProgressBar {
        id: progressBar1
        x: 315
        y: 268
    }

    Text {
        id: text2
        x: 522
        y: 268
        text: qsTr("50 C")
        font.pixelSize: 24
    }

    Text {
        id: text3
        x: 101
        y: 352
        text: qsTr("Humidity")
        font.pixelSize: 24
    }

    ProgressBar {
        id: progressBar2
        x: 315
        y: 354
    }

    Text {
        id: text4
        x: 521
        y: 352
        text: qsTr("90%")
        font.pixelSize: 24
    }

    Image {
        id: image1
        x: 46
        y: 107
        width: 150
        height: 150
        source: "PIC-500x500.png"
    }

    Text {
        id: text5
        x: 51
        y: 90
        text: qsTr("PIC16F877A")
        font.pixelSize: 24
    }

    Text {
        id: text6
        x: 488
        y: 90
        text: qsTr("DHT11")
        font.pixelSize: 24
    }

    Image {
        id: image2
        x: 475
        y: 151
        width: 100
        height: 100
        source: "DHT11-800x800.jpg"
    }

    Text {
        id: text7
        x: 261
        y: 352
        text: qsTr("20%")
        font.pixelSize: 24
    }

    Text {
        id: text8
        x: 262
        y: 264
        text: qsTr("0 C")
        font.pixelSize: 24
    }

    Text {
        id: text9
        x: 46
        y: 424
        text: qsTr("Nguyễn Tài Tuấn")
        font.pixelSize: 16
    }

    Text {
        id: text10
        x: 459
        y: 425
        text: qsTr("Ngô Thanh Tùng")
        font.pixelSize: 16
    }

    Label {
        id: label1
        x: 159
        y: 19
        text: qsTr("Đo nhiệt độ và độ ẩm")
        font.pointSize: 25
    }

    Image {
        id: image3
        x: 35
        y: 252
        width: 60
        height: 60
        source: "medium_temperature-512.png"
    }

    Image {
        id: image4
        x: 35
        y: 336
        width: 60
        height: 60
        source: "66b1a0b18b.png"
    }

    Text {
        id: text11
        x: 226
        y: 447
        text: qsTr("KSTN Cơ điện tử K60")
        font.pixelSize: 20
    }
}

