#ifndef SECUREAPP_H
#define SECUREAPP_H

#include "veins/modules/application/ieee80211p/BaseWaveApplLayer.h" // 引入 Veins 的基礎應用層

namespace veins {

class SecureApp : public BaseWaveApplLayer {
  public:
    virtual void initialize(int stage) override; // 初始化函式
    virtual void finish() override;             // 結束函式

  protected:
    virtual void onWSM(BaseWaveShortMessage* wsm) override; // 處理收到的 WSM 訊息
    // virtual void onWSA(WaveServiceAdvertisment* wsa) override; // 若需處理 WSA，取消此行註解
    virtual void handleSelfMsg(cMessage* msg) override;     // 處理自身訊息 (如計時器)
    // virtual void handlePositionUpdate(cObject* obj) override; // 若需處理位置更新，取消此行註解
};

} // namespace veins

#endif // SECUREAPP_H

