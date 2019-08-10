//
// Created by 冉高飞 on 2019-02-20.
//

#include <QQmlApplicationEngine>
#include <QWindow>
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

#include "bluetoothmodel.h"
#include "logmodel.h"
#include "TcpServerModel.h"
#include "UdpServerModel.h"
#include "notepadmodel.h"
#include "TcpClientModel.h"
#include "UdpClientModel.h"
#include "settingtool.h"
#include "TranslatorTool.h"
//#include "sqlitetool.h"

#define LANGUAGE_DIR ":/assets/lauguage"

/**
 * @brief initSettings
 * 初始化配置文件信息
 */
void initSettings(){
    QCoreApplication::setOrganizationName("rangaofei");
    QCoreApplication::setOrganizationDomain("rangaofei.cn");
    QCoreApplication::setApplicationName("SSokit");
}

/**
 * @brief registerQml
 * 注册所有的qml文件
 */
void registerQml(){
    qmlRegisterType<NotepadModel>("src.notepadmodel", 1, 0, "NotepadModel");
    qmlRegisterType<BlueToothModel>("src.bluetoothmodel", 1, 0, "BlueToothModel");
    qmlRegisterType<TcpServerModel>("src.tcpservermodel", 1, 0, "TcpServerModel");
    qmlRegisterType<UdpServerModel>("src.udpservermodel", 1, 0, "UdpServerModel");
    qmlRegisterType<TcpClientModel>("src.tcpclientmodel", 1, 0, "TcpClientModel");
    qmlRegisterType<UdpClientModel>("src.udpclientmodel", 1, 0, "UdpClientModel");
    qmlRegisterType<SettingTool>("src.settingtool",1,0,"SettingTool");
    qmlRegisterType<ItemPort>("src.itemport", 1, 0, "ItemPort");
}

/**
 * 程序入口
 */
int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    initSettings();
    TranslatorTool translatorTool;
    translatorTool.initLanguage();
    registerQml();

    //    SQLiteTool *s=new SQLiteTool();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/SSokit.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return QApplication::exec();
}