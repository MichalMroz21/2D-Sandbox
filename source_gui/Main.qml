import QtQuick 2.15
import QtQuick.Controls 2.15

import TwoD.Sandbox 1.0

Window {
    width: 800
    height: 600
    visible: true
    title: "2D Sandbox"

    Rectangle {
        width: parent.width
        height: parent.height

        Column {
            width: parent.width
            height: parent.height

            Rectangle {
                width: parent.width
                height: parent.height / 8
                color: "#282828"

                Row {
                    anchors.centerIn: parent

                    Button {
                        text: "Start"
                        onClicked: {
                            console.log("Start button clicked")
                        }
                    }

                    Button {
                        text: "Stop"
                        onClicked: {
                            console.log("Stop button clicked")
                        }
                    }
                }
            }

            OpenGLItem {
                width: parent.width
                height: parent.height * 7 / 8
            }
        }
    }
}
