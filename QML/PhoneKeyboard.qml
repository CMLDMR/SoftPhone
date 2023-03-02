import QtQuick 2.15
import QtQuick.Layouts
import com.softphone.keyboard 1.0
import com.softphone.global 1.0


Rectangle{

    id: keyboardPadID
    property int itemWidth: 100
    property int itemHeight: 100
    property KeyBoard mKeyboard : Global.getKeyBoardModel()

    property bool opened: false

    width: 320
    height: 480

    color: "transparent"

    Rectangle{
        x: -50
        y: 0
        width: 50
        height: 50
        color: "red"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if( !opened ){
                    openUPKeyboard.start();
                }else{
                    closeUPKeyboard.start();
                }
                opened = !opened;

            }
        }
    }

    Rectangle{
        width: parent.width
        height: 50

        color: "aliceblue"

        TextInput{
            id: numberTextid
            anchors.fill: parent
            anchors.rightMargin: 30
            horizontalAlignment: TextInput.AlignHCenter
            verticalAlignment: TextInput.AlignVCenter
            font.pointSize: 22
            font.bold: true
            validator: RegularExpressionValidator { regularExpression: /[0-9]+/ }

            Text{
                anchors.centerIn: parent
                visible: !parent.text
                color: "gray"
                text: "Numara Giriniz"
                font.pointSize: 22
            }
        }


        Rectangle{
            color: "red"
            width: 50
            height: parent.height
            anchors.right: parent.right

            Text{
                anchors.centerIn: parent
                text: "DEL"
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    numberTextid.text = numberTextid.text.substring(0, numberTextid.text.length - 1);
                }
            }
        }


    }


    GridLayout{
        anchors.fill: parent
        anchors.topMargin: 50
        columns: 3
        columnSpacing: 5
        rowSpacing: 5

        Repeater{
            model: mKeyboard
            delegate: PhoneButton{
                keyBoardName: keyboardName
                onPressedKeyBoard: {
                    if( numberTextid.text.length <= 11 ){
                        mKeyboard.playSound(keyboardName);
                        numberTextid.text = numberTextid.text + keyboardName
                    }
                }
            }
        }
    }


    NumberAnimation{
        id: openUPKeyboard
        target: keyboardPadID
        property: "x"
        from: mainWindowID.width
        to: mainWindowID.width-320
        duration: 200
    }

    NumberAnimation{
        id: closeUPKeyboard
        target: keyboardPadID
        property: "x"
        from: mainWindowID.width-320
        to: mainWindowID.width
        duration: 200
    }

}

