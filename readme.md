# secureVeins README

這份文件總結了在 **OMNeT++ 6.0.3** 環境下，基於內建 `samples/veins` 範例，轉向使用 **Veins 5.3.1** 完整版本，並開發自訂應用模組 `SecureApp` 的完整流程與經驗。

---

## 目錄

1. [環境需求](#環境需求)
2. [取得並編譯 Veins 5.3.1](#取得並編譯-veins-531)
3. [配置及編譯 secureVeins 專案](#配置及編譯-secureveins-專案)
4. [SecureApp 範例：C++ 與 NED 修改](#secureapp-範例c-與-ned-修改)
5. [常見問題與解法](#常見問題與解法)
6. [執行模擬](#執行模擬)
7. [後續擴充建議](#後續擴充建議)

---

## 環境需求

* **OMNeT++ 6.0.3** (Academic Public License)
* **SUMO 1.20.0** (已編譯安裝；設置 `$SUMO_HOME`)
* **Veins 5.3.1** (官方 GitHub)
* C++ 編譯工具鏈 (g++, make)

---

## 取得並編譯 Veins 5.3.1

1. **Clone 官方倉庫**

   ```bash
   cd ~/omnetpp-6.0.3
   git clone --depth 1 --branch veins-5.3.1 https://github.com/sommer/veins.git
   ```

2. **載入 OMNeT++ 環境**

   ```bash
   source ~/omnetpp-6.0.3/setenv
   ```

3. **生成 Makefile**

   ```bash
   cd veins
   ./configure
   ```

4. **編譯**

   ```bash
   make MODE=release -j$(nproc)
   ```

   * `MODE=debug` 可用於偵錯

---

## 配置及編譯 secureVeins 專案

假設專案路徑為 `~/omnetpp-6.0.3/samples/secureVeins`，並且 Veins 放在 `../veins`：

1. **清理舊檔**

   ```bash
   cd samples/secureVeins
   rm Makefile
   rm -rf out/
   ```
2. **呼叫 opp\_makemake**

   ```bash
   opp_makemake -f \
     -O out/clang-release \
     -I../../veins/src \
     -L../../veins/src -lveins \
     --deep
   ```
3. **編譯**

   ```bash
   make MODE=release -j$(nproc)
   ```

> **注意**：確保 `-I` 指向 `veins/src`，連結時帶上 `-L… -lveins`，並使用 `--deep` 讓所有子目錄的來源都納入。

---

## SecureApp 範例：C++ 與 NED 修改

### 1. SecureApp.h

```cpp
#ifndef SECUREAPP_H
#define SECUREAPP_H

#include "veins/modules/application/ieee80211p/DemoBaseApplLayer.h"
#include "veins/modules/messages/BaseFrame1609_4_m.h"
#include "veins/modules/mac/ieee80211p/DemoBaseApplLayerToMac1609_4Interface.h"

namespace veins {

class SecureApp : public DemoBaseApplLayer {
  public:
    virtual void initialize(int stage) override;
    virtual void finish() override;
  protected:
    virtual void onWSM(BaseFrame1609_4* wsm) override;
    virtual void handleSelfMsg(cMessage* msg) override;
};

} // namespace veins
#endif // SECUREAPP_H
```

### 2. SecureApp.cc

```cpp
#include "SecureApp.h"
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
    // 呼叫父類進行預設處理（含 delete wsm）
    DemoBaseApplLayer::onWSM(wsm);

    // 透過 controlInfo 介面取得 MAC 層送來的 source address
    auto macIf = check_and_cast<DemoBaseApplLayerToMac1609_4Interface*>(
        wsm->getControlInfo());
    auto sender = macIf->getMACAddress();

    EV_INFO << "[SecureApp] 收到 WSM: " << wsm->getName()
            << " 來源車輛 MAC: " << sender << std::endl;

    // TODO: 加入解密、驗證邏輯
}

void SecureApp::handleSelfMsg(cMessage* msg) {
    if (strcmp(msg->getName(), "sendBeaconTimer") == 0) {
        EV_INFO << "[SecureApp] Beacon Timer 觸發" << std::endl;
        // e.g. sendWSM(createBeacon());
    }
    delete msg;
}

} // namespace veins
```

### 3. SecureApp.ned

```ned
package org.car2x.veins.modules.application.secureApp;

import org.car2x.veins.modules.application.ieee80211p.DemoBaseApplLayer;

simple SecureApp extends DemoBaseApplLayer {
    @class(veins::SecureApp);
    // 自訂參數範例
    double beaconInterval @unit(s) = default(1s);
}
```

---

## 常見問題與解法

| 問題                                 | 解法                                                        |
| ---------------------------------- | --------------------------------------------------------- |
| 找不到 BaseWaveApplLayer.h            | 改繼承 `DemoBaseApplLayer.h`（Veins 5.x 改名）                   |
| 找不到 SimpleLogger.h                 | Veins 5.x 移除，改用 `EV_INFO` / `EV_DEBUG` / `EV_WARN` 等      |
| 無法取 `getSenderAddress()`           | 用 `controlInfo` → `DemoBaseApplLayerToMac1609_4Interface` |
| `opp_makemake` 產生錯誤 `INCLUDE_PATH` | 移除 `INCLUDE_PATH` 參數，只留 `-I` / `-L -lveins` / `--deep`    |

---

## 執行模擬

```bash
cd samples/secureVeins/examples/veins
veins_run -u Qtenv -n .:../../src/veins -c Default omnetpp.ini
```

* **Qtenv** 顯示 GUI 與 log
* **--start** 可加到 `sumo-gui`，避免手動點 Start

---

## 後續擴充建議

* 若需要與 **INET** 整合，可將 Veins 作為外部 library (opp\_cmake 或 CMake)
* 推薦使用 **Veins 5.3.1** 正式版，方便後續加入 Simu5G/Plexe
* 安全機制可在 `onWSM()` 裡加入「簽章驗證」、「AES 解密」等邏輯，僅對特定 `.msg` 做 `dynamic_cast`

---

> 建議將此 README.md 放在 `samples/secureVeins` 專案根目錄，並在首次 clone 後先行閱讀，以掌握整體流程。
