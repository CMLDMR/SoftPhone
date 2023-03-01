import QtQuick 2.15

Rectangle{
    id: keyboardid
    property string keyBoardName
    anchors.margins: 5
    color: "green"
    border.width: 1
    border.color: "black"
    width: itemWidth
    height: itemHeight

    Text {
        id: textid
        text: qsTr(keyBoardName)
        anchors.centerIn: parent
        font.pointSize: 20
        color: "white"
        font.bold: true
    }

    MouseArea{
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor


        onPressed: {
            keyboardid.color = "dimgray"
            textid.color = "black"
        }

        onReleased: {
            keyboardid.color = "green"
            textid.color = "white"
        }
    }


}
