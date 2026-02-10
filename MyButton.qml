import QtQuick 2.15

Item {
    property var callback
    property int index
    Rectangle{
        anchors.fill: parent
    }

    Rectangle {
        id:rect
        height:parent.height -10
        width:parent.width - light.width -20
        color: "blue"
        radius:parent.width/3
        anchors.left:light.right
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 5
    }
    Rectangle{
        id:light
        anchors.left: parent.left
        anchors.leftMargin: 5
        color: "darkred"
        width: 25
        height: width
        radius: width/2
        anchors.top: parent.top
        anchors.topMargin: parent.height/4

    }

    MouseArea{
        anchors.fill:parent
        onPressed: {
            if(callback){
                callback(index);
            }

            rect.color="green"
            light.color="red"
        }
        onReleased:{
            rect.color="blue"
            light.color="darkred"
        }

    }
}
