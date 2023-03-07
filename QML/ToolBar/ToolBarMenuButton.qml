import QtQuick 2.15

Rectangle{
    color: "dimgray"
    property string menuName
    Text {
        id: rehberBtnid
        anchors.centerIn: parent
        text: qsTr(menuName)
        font.pointSize: 15
        font.bold: true
        color: "lightgray"
    }

    MouseArea{
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor

        onEntered: {
            rehberBtnid.color = "dimgray"
            parent.color = "aliceblue"
        }

        onExited: {
            rehberBtnid.color = "lightgray"
            parent.color = "dimgray"
        }

        onClicked: {
            console.log(menuName);
        }
    }

}
