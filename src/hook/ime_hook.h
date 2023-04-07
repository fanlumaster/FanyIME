#pragma once

#include <Windows.h>

#include <codecvt>
#include <iostream>
#include <locale>
#include <string>
#include <unordered_map>
#include <vector>

#include "../../libs/sqlite/sqlite3.h"

// 全局变量，用来捕捉键盘的字符
extern std::vector<char> charVec;
// 分页 map
extern std::unordered_map<std::string, std::vector<std::vector<std::pair<std::string, long>>>> sqlPageMap;
// 候选字的存储位置
extern std::vector<std::vector<std::pair<std::string, long>>> candidateVec;
extern std::vector<std::pair<std::string, long>> curCandidateVec;
// 候选框中的序号
extern int pageNo;
// 左右引号的标志
extern bool quoteFlag;
// 数据库
extern sqlite3* db;

// 整体输入法状态的一个控制
// 默认是 0，也就是英文状态
extern bool IMEState;
extern std::string IMEStateToast;

extern std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

LRESULT CALLBACK KBDHook(int nCode, WPARAM wParam, LPARAM lParam);

// 打印一维 vector
void printOneDVector(std::vector<std::pair<std::string, long>> myVec);

// 模拟按下字符串中的每个字符
void sendStringToCursor(const std::wstring& str);