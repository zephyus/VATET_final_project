package org.car2x.veins.modules.application;

// 告訴 OMNeT++ 在哪些子目錄中尋找 NED 檔案
// 原本可能只有 ieee80211p 和 traci，我們加上 secureApp
@nedfolders(., ieee80211p, traci, secureApp);

// 其他可能已存在的 import 或註解...
