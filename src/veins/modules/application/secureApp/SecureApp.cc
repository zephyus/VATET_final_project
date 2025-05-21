#include "SecureApp.h" // 引入我們剛才定義的標頭檔
#include "veins/modules/messages/BaseFrame1609_4_m.h" // 引入訊息定義 (例如 BSM)
#include "veins/base/utils/SimpleLogger.h" // 引入日誌工具

namespace veins {

Define_Module(veins::SecureApp); // 讓 OMNeT++ 能夠識別這個模組

void SecureApp::initialize(int stage) {
    BaseWaveApplLayer::initialize(stage); // 呼叫父類別的 initialize
    if (stage == 0) {
        // 您的初始化邏輯寫在這裡
        // 例如：設定計時器、讀取參數等
        EV_INFO << "[SecureApp] 初始化完成 (Initializing...)" << std::endl;
    }
}

void SecureApp::finish() {
    BaseWaveApplLayer::finish(); // 呼叫父類別的 finish
    // 您的清理邏輯寫在這裡
    EV_INFO << "[SecureApp] 模擬結束 (Finishing.)" << std::endl;
}

void SecureApp::onWSM(BaseWaveShortMessage* wsm) {
    // 處理收到的 WAVE Short Message (WSM)
    EV_INFO << "[SecureApp] 收到 WSM: " << wsm->getName()
            << " 從車輛: " << wsm->getSenderL2Address() << std::endl;

    // 在這裡加入您的安全檢查或訊息處理邏輯
    // 例如: if (isMessageSecure(wsm)) { processValidMessage(wsm); }

    delete wsm; // 處理完畢後記得刪除訊息以釋放記憶體
}

/* // 若您在 .h 檔中取消註解 onWSA，也請取消此段註解
void SecureApp::onWSA(WaveServiceAdvertisment* wsa) {
    // 處理收到的 WAVE Service Advertisement (WSA)
    EV_INFO << "[SecureApp] 收到 WSA: " << wsa->getName() << std::endl;
    delete wsa;
}
*/

void SecureApp::handleSelfMsg(cMessage* msg) {
    // 處理排程給自己的訊息 (例如計時器觸發的事件)
    if (strcmp(msg->getName(), "sendBeaconTimer") == 0) {
        // 假設您設定了一個叫做 "sendBeaconTimer" 的計時器
        // 在這裡加入傳送 beacon 的邏輯
        EV_INFO << "[SecureApp] 計時器觸發，準備傳送訊息..." << std::endl;
    }
    // 如果這個訊息不是 BaseWaveApplLayer 的標準訊息，處理完後要 delete
    // BaseWaveApplLayer::handleSelfMsg(msg); // 如果父類別也需要處理某些自訂訊息
    delete msg; // 如果是您自己建立並排程的訊息，通常需要刪除
}

/* // 若您在 .h 檔中取消註解 handlePositionUpdate，也請取消此段註解
void SecureApp::handlePositionUpdate(cObject* obj) {
    BaseWaveApplLayer::handlePositionUpdate(obj);
    // 當車輛位置更新時觸發的動作
    // 例如：根據新位置決定是否廣播訊息
}
*/

} // namespace veins
