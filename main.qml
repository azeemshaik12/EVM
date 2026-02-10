import QtQuick 2.15
import QtQuick.Window 2.15
import Party.Models 1.0

Window {
    width: 400
    height: 600
    visible: true

    title: qsTr("EVM")
    color: "#E7ECEA"

    PartyModel {
        id: partyModel
    }
    Component{
        id:my_delegate
        Item {
            width: myView.width
            height: 50
            Rectangle{
                id:s_no
                width:50
                height: 50
                Text{
                    anchors.centerIn: parent
                    text:index+1
                }
            }
            Rectangle{
                id:m_name
                width:100
                height: 50
                anchors.left: s_no.right
                anchors.leftMargin: 2
                Text {
                    text: partyname
                    anchors.centerIn: parent
                }
            }
            Rectangle{
                id:m_symbol
                anchors.left: m_name.right
                anchors.leftMargin: 2
                width:50
                height: 50
                Image {
                    id: symbol
                    anchors.fill: parent
                    source: model.symbol
                    fillMode: Image.PreserveAspectFit
                    smooth: true              // makes scaling look clean
                    mipmap: true              // improves quality when shrinking
                    antialiasing: true
                    cache: true               // keeps in memory (faster)
                }
            }
            MyButton{
                anchors.left: m_symbol.right
                anchors.leftMargin: 2
                width:150
                height:50
                callback: vote
                index: model.index
            }
        }
    }

    ListView {
        id: myView
        anchors.fill: parent
        anchors.leftMargin: 20
        anchors.topMargin: 30
        model: partyModel
        spacing :2
        interactive: false
        delegate: my_delegate
    }

    function vote(index){
        partyModel.vote(index);
    }

}
