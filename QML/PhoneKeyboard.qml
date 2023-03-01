import QtQuick 2.15
import QtQuick.Layouts
import com.softphone.keyboard 1.0
import com.softphone.global 1.0


    Rectangle{

        property int itemWidth: 100
        property int itemHeight: 100
        property KeyBoard mKeyboard : Global.getKeyBoardModel()


        anchors.fill: parent
        color: "dimgray"


        Rectangle{
            width: 310
            height: 480
            anchors.centerIn: parent


            GridLayout{
                anchors.fill: parent
                columns: 3
                columnSpacing: 5
                rowSpacing: 5




                Repeater{
                    model: mKeyboard

                    delegate: PhoneButton{
                        keyBoardName: keyboardName

                        MouseArea{
                            anchors.fill: parent

                            onPressed: {
                                console.log("Lickce " + keyboardName);

                                mKeyboard.playSound(keyboardName);
                            }
                        }

                    }
                }

            }

        }


    }

