/*
    背景：此版本更新了 flyciku.db 为我日常使用的完整版词库

    目标：
        在 hookWin09 的基础上，
        解决多字和退格键的处理。

    实际完成情况：

    下一个版本的目标：
*/
#include <Windows.h>

#include <cctype>
#include <codecvt>
#include <iostream>
#include <locale>

#include "./flypytblsqlite.h"
#include "./src/hook/ime_hook.h"
#include "./src/sqlite/sqlite_wrapper.h"

int main() {
    // 注册和设置钩子
    HHOOK kbd = SetWindowsHookEx(WH_KEYBOARD_LL, &KBDHook, 0, 0);
    // 初始化小鹤双拼的码表，纯双拼二码
    std::cout << "开始初始化..." << '\n';
    std::string dbPath = "../../src/flyciku.db";
    db = openSqlite(dbPath);
    std::cout << "初始化完成" << '\n';
    std::cout << IMEStateToast << '\n';

    MSG message;
    // 消息循环
    while (GetMessage(&message, NULL, NULL, NULL) > 0) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    // 注销钩子
    UnhookWindowsHookEx(kbd);

    // 关闭数据库
    closeSqliteDB(db);

    return 0;
}
