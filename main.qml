import QtQuick
import "QML"
//import com.belediye 1.0
//import com.belediye.global 1.0

Window {
    id: mainWindowID
    width: 1280
    height: 780
    visible: true
    title: qsTr("Soft Phone")


    ToolBar{
        x: 0
        y: 0
        width: parent.width
        height: 50
    }






    PhoneKeyboard{
        x: parent.width
        y: 100
    }



}
