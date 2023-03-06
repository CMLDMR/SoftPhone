import QtQuick 2.15
import QtQuick.Layouts

import com.softphone.toolbarItem 1.0



ToolBarItem{
    width: parent.width
    height: 50

    RowLayout{
        anchors.fill: parent

        Rectangle{
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "red"
            Text {
                id: name
                text: qsTr("Rehber")
            }
        }

        Rectangle{
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "green"
            Text {
                text: qsTr("TC Bank")
            }
        }

        Rectangle{
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "green"
            Text {
                text: qsTr("Talepler")
            }
        }

        Rectangle{
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "green"
            Text {
                text: qsTr("Bilgi Edinme")
            }
        }

        Rectangle{
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "green"
            Text {
                text: qsTr("SIP Ayarları")
            }
        }
    }

}

