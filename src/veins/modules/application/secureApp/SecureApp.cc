// SecureApp.cc
#include "SecureApp.h"
// 引入 controlInfo 介面定義
#include "veins/modules/mac/ieee80211p/DemoBaseApplLayerToMac1609_4Interface.h"

namespace veins {
Define_Module(SecureApp);

void SecureApp::initialize(int stage) {
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {
        EV_INFO << "[SecureApp] 初始化完成" << std::endl;
    }
}

void SecureApp::finish() {
    DemoBaseApplLayer::finish();
    EV_INFO << "[SecureApp] 模擬結束" << std::endl;
}

void SecureApp::onWSM(BaseFrame1609_4* wsm) {
    // 1) 先交給父類處理（包含統計、delete wsm）
    DemoBaseApplLayer::onWSM(wsm);

    // 2) 從 controlInfo 取回 MAC 層傳遞過來的 sender address
    auto macInterface = check_and_cast<
        DemoBaseApplLayerToMac1609_4Interface*
    >(wsm->getControlInfo());
    LAddress::L2Type sender = macInterface->getMACAddress();

    // 3) 日誌輸出
    EV_INFO << "[SecureApp] 收到 WSM: " << wsm->getName()
            << " (類型: " << wsm->getClassName() << ")"
            << " 來源車輛 MAC: " << sender
            << std::endl;

    // 4) 在此加入您的加密/驗證或其他自訂邏輯
    //    例如： decryptAndVerify(wsm->getPayload(), sender);

    // 無需再手動 delete wsm（父類已處理）
}

void SecureApp::handleSelfMsg(cMessage* msg) {
    if (strcmp(msg->getName(), "sendBeaconTimer") == 0) {
        EV_INFO << "[SecureApp] Beacon Timer 觸發，準備傳送…" << std::endl;
        // 範例： sendWSM(createBeacon());
    }
    delete msg;
}

} // namespace veins

