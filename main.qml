import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.0
Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Финансовый Учет")
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width

    Interface {
        anchors.fill: parent
    }
}
