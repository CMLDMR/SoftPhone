import QtQuick 2.15
import QtQuick.Layouts

import com.softphone.toolbarItem 1.0



ToolBarItem{
    width: parent.width
    height: 50

    RowLayout{
        anchors.fill: parent

        ToolBarMenuButton{
            Layout.fillWidth: true
            Layout.fillHeight: true
            menuName: "Rehber"
        }

        ToolBarMenuButton{
            Layout.fillWidth: true
            Layout.fillHeight: true
            menuName: "TC DB"
        }

        ToolBarMenuButton{
            Layout.fillWidth: true
            Layout.fillHeight: true
            menuName: "Talepler"
        }

        ToolBarMenuButton{
            Layout.fillWidth: true
            Layout.fillHeight: true
            menuName: "Bilgi Edinme"
        }

        ToolBarMenuButton{
            Layout.fillWidth: true
            Layout.fillHeight: true
            menuName: "SIP Ayarları"
        }

    }

}

