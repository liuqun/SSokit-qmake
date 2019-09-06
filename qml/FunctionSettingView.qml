import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import src.settingtool 1.0
import src.strings 1.0

Item {
    anchors.fill:parent
    anchors.topMargin: 50
    GroupBox{
        id:layout_window
        anchors.topMargin: 20
        implicitWidth: parent.width
        background: Rectangle{
            color: "#00000000"
        }
        ColumnLayout{
            anchors.left: parent.left
            anchors.right: parent.right
            GeneralCheckBox{
                Layout.alignment: Qt.AlignRight
                 text: Strings.settingEnableHovver
                checked: SettingTool.getEnableLogHover()
                onCheckStateChanged: {
                    SettingTool.setEnableLogHover(checked)
                }

            }
            GeneralCheckBox{
                Layout.alignment: Qt.AlignRight
                text: Strings.settingShowClear
                checked: SettingTool.getShowSendClear()
                onCheckStateChanged: {
                    SettingTool.setShowSendClear(checked)
                }
            }
            Rectangle{
                Layout.topMargin: 20
                Layout.fillWidth: true
                Layout.preferredHeight:1
                color: "#bdbdbd"
            }
        }
    }
}
