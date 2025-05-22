// SecureApp.h
#ifndef SECUREAPP_H
#define SECUREAPP_H

#include "veins/modules/application/ieee80211p/DemoBaseApplLayer.h"
#include "veins/modules/messages/BaseFrame1609_4_m.h"
// 引入 MAC→App 介面
#include "veins/modules/mac/ieee80211p/DemoBaseApplLayerToMac1609_4Interface.h"

namespace veins {

class SecureApp : public DemoBaseApplLayer {
  public:
    virtual void initialize(int stage) override;
    virtual void finish() override;

  protected:
    /** 收到 1609.4 frame 時被呼叫 */
    virtual void onWSM(BaseFrame1609_4* wsm) override;
    /** 處理自我訊息 */
    virtual void handleSelfMsg(cMessage* msg) override;
};

} // namespace veins

#endif // SECUREAPP_H

