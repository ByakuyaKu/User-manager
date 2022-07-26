import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import "./elements"

Window {
    id: window
    color:"lightgray"
    width: 640
    height: 640
    visible: true
    title: qsTr("User manager")
    //    ScrollView {
    //        id: view
    //        width: 200
    //        height: 200
    //clip: true
    //minimumHeight: 640
    //minimumWidth: 640
    ScrollView{
        anchors.fill: parent

    ScrollBar.vertical: ScrollBar {}
    ButtonGroup {
        //buttons: column.children
        id: btnGroup
    }

    Row {
        id: row
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 10
        //anchors.topMargin: 10
        //anchors.leftMargin: 10
        width: parent.width-row.anchors.margins*2/7
        spacing: 5
        Button {
            height: 30
            //width: (parent.width-row.anchors.margins*2-row.spacing*6)/7
            text: qsTr("DAB")
        }

        Button {
            //width: (parent.width-row.anchors.margins*2-row.spacing*6)/7
            height: 30
            text: qsTr("FM")
        }

        Button {
            //width: (parent.width-row.anchors.margins*2-row.spacing*6)/7
            height: 30
            text: qsTr("AM")
        }
        Button {
            //width: (parent.width-row.anchors.margins*2-row.spacing*6)/7
            height: 30
            text: qsTr("AM")
        }
        Button {
            width: (parent.width-row.anchors.margins*2-row.spacing*6)/7
            height: 30
            text: qsTr("AM")
        }
        Button {
            //width: (parent.width-row.anchors.margins*2-row.spacing*6)/7
            height: 30
            text: qsTr("AM")
        }
        Button {
            //width: (parent.width-row.anchors.margins*2-row.spacing*6)/7
            height: 30
            text: qsTr("AM")
        }
    }

    TabBar {
        id: bar
        width: parent.width
        anchors.top: row.bottom
        anchors.left: window.left
        anchors.topMargin: 10

        TabButton {
            text: qsTr("Users")
            implicitWidth: 100
            width: 100
        }
        TabButton {
            implicitWidth: 100
            text: qsTr("Groups")
            width: 100
        }
    }

    StackLayout {
        width: parent.width
        currentIndex: bar.currentIndex
        Item {
            id: usersTab
            Text {
                id: test
                //text: user.getLocalUsers()
            }
            Text {
                id: ssss
                //text: qsTr(user.getLocalUsers()[0].UID)
                color: "black"
            }
        }


        Item {
            id: groupsTab
            Rectangle {
                id: userListRect
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.margins: 20
                anchors.topMargin: 110

                width: window.width-anchors.margins*2
                height: window.height - anchors.topMargin-anchors.margins
                //width: 300
                //height: 300

                border.color: "lightblue"
                border.width: 0.5
                radius: 5
                color: "white"
                //property string textt: logic.getLocalUsers()
                Text {
                    id: sas
                    //text: qsTr(logic.getLocalUsers())
                    color: "black"
                }
                ListView {
                    id: userList
                    //anchors.fill: parent
                    width: parent.width-2
                    height: parent.height-2
                    anchors.centerIn: parent
                    model: userListModel
                    //highlight: Rectangle { color: "lightblue"; radius: 5 }
                    focus: true
                    spacing: -1
                    keyNavigationEnabled: true
                    ScrollBar.vertical: ScrollBar {}
                    delegate: Component {
                        Rectangle {
                            id: wrapper
                            width: userList.width
                            height: 20
                            color: ListView.isCurrentItem ? "lightblue" : "white"
                            Text {
                                //id: contactInfo
                                text: UID + "   " + RegistratorName + "   " +  FullName + "   " +  HomeDir + "   " +  LoginEngine
                                color: "black"
                                //anchors.centerIn: parent
                            }
                            MouseArea
                            {
                                anchors.fill: parent
                                onClicked:
                                {
                                    userList.currentIndex = index
                                    //itemClicked();
                                    }
                                }
                        }
                    }


                    ListModel {
                        id: userListModel

                        ListElement {
                            UID:'efg'
                            RegistratorName:'456'
                            FullName:'456'
                            HomeDir:'456'
                            LoginEngine:'456'
                        }
                        ListElement {
                            UID:'efg'
                            RegistratorName:'456'
                            FullName:'456'
                            HomeDir:'456'
                            LoginEngine:'456'
                        }
                        ListElement {
                            UID:'efg'
                            RegistratorName:'456'
                            FullName:'456'
                            HomeDir:'456'
                            LoginEngine:'456'
                        }
                        ListElement {
                            UID:'efg'
                            RegistratorName:'456'
                            FullName:'456'
                            HomeDir:'456'
                            LoginEngine:'456'
                        }
                        ListElement {
                            UID:'efg'
                            RegistratorName:'456'
                            FullName:'456'
                            HomeDir:'456'
                            LoginEngine:'456'
                        }
                    }
                }
            }
        }
    }
    Connections {
            target: logic
            //onDataChanged: console.log("The application data changed!")
            //onTest()
        }
}
}
