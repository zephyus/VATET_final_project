//
// SecureApp.ned
//
package org.car2x.veins.modules.application.secureApp;

// 引入 DemoBaseApplLayer，這是 Veins 5.x 應用層的建議基礎 NED 模組
import org.car2x.veins.modules.application.ieee80211p.DemoBaseApplLayer;

// SecureApp 繼承自 DemoBaseApplLayer
simple SecureApp extends DemoBaseApplLayer
{
    parameters:
        // 把 NED 與 C++ 類別繫結 (veins::SecureApp 是您 C++ 類別的完整名稱)
        @class(veins::SecureApp);

        // 您原有的圖示設定
        @display("i=block/app");

        // 您原有的自訂參數範例（可保留、修改或刪除）
        double beaconInterval @unit(s) = default(1s);
        bool   enableCrypto           = default(true);

    gates:
        // DemoBaseApplLayer 已經定義了必要的 gates (lowerLayerIn/Out, lowerControlIn/Out)
        // 通常不需要在這裡額外宣告，除非您的 SecureApp 有特殊的額外介面需求
}
