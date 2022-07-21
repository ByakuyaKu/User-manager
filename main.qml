import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import "./elements"

Window {
    id: window
    color:"lightgray"
    width: 640
    height: 480
    visible: true
    title: qsTr("User manager")

    Rectangle {
        id: rect

        anchors.left: parent.left
        anchors.top: parent.top
        anchors.margins: 20

        width: 150
        height: window.height - rect.anchors.margins*2

        color: "white"

        ColumnLayout {
            spacing: 1
            CustomTabBtn {
                text: qsTr("Users")
                width: rect.width
                height: 30
            }
            CustomTabBtn {
                text: qsTr("Local users")
                width: rect.width
                height: 30
            }
            CustomTabBtn {
                text: qsTr("...")
                width: rect.width
                height: 30
            }
        }
    }

    Rectangle {
        id: userList

        anchors.left: rect.right
        anchors.top: parent.top
        anchors.margins: 20

        width: 150
        height: window.height - userList.anchors.margins*2

        color: "white"

        ColumnLayout {
            spacing: 1
            CustomTabBtn {
                text: qsTr("User 1")
                width: userList.width
                height: 30
            }
            CustomTabBtn {
                text: qsTr("user 2")
                width: userList.width
                height: 30
            }
            CustomTabBtn {
                text: qsTr("...")
                width: userList.width
                height: 30
            }
            CustomTabBtn {
                text: qsTr("...")
                width: userList.width
                height: 30
            }
            CustomTabBtn {
                text: qsTr("...")
                width: userList.width
                height: 30
            }
            CustomTabBtn {
                text: qsTr("...")
                width: userList.width
                height: 30
            }
            CustomTabBtn {
                text: qsTr("...")
                width: userList.width
                height: 30
            }
            CustomTabBtn {
                text: qsTr("...")
                width: userList.width
                height: 30
            }
        }
    }

    Rectangle {
        id: userInfo

        anchors.left: userList.right
        anchors.top: parent.top
        anchors.margins: 20

        implicitWidth: window.width - userList.width - rect.width - rect.anchors.margins - userList.anchors.margins - userInfo.anchors.margins*2
        width: window.width - userList.width - rect.width - rect.anchors.margins - userList.anchors.margins - userInfo.anchors.margins*2
        height: window.height - userInfo.anchors.margins*2

        color: "white"


    }
}

