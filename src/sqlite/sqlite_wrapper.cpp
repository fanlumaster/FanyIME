#include "./sqlite_wrapper.h"

struct UserData {
    int& itemCount;
    std::vector<std::pair<std::string, long>>& result;
};

// 回调函数
int queryPinyinCallback(void* data, int argc, char** argv, char** azColName);

sqlite3* openSqlite(std::string dbPath) {
    sqlite3* db;
    int rc = sqlite3_open(dbPath.c_str(), &db);
    if (rc) {
        // Todo: 异常处理
        std::cout << "open db error!" << '\n';
        return nullptr;
    }
    std::cout << "db opened successfully!" << '\n';
    return db;
}

/*
    单字查询
    从某一个表中模糊查询一个拼音
    参数：
        pinyin: string
    返回值：vector<vector<pair<string, long>>>
*/
std::vector<std::pair<std::string, long>> queryPinyin(sqlite3* db, std::string pinyin) {
    std::vector<std::pair<std::string, long>> resVec;
    std::string tblName = "fullpinyinsimple";
    std::string querySQL = "select * from " + tblName + " where key like " + "'" + pinyin + "%'" + " and length(key) == 2 order by weight desc limit 300";
    // std::cout << querySQL << '\n';
    int result;
    char* errMsg = nullptr;
    int itemCount = 0;
    UserData userData{itemCount, resVec};
    // 查询
    result = sqlite3_exec(db, querySQL.c_str(), queryPinyinCallback, &userData, &errMsg);
    // std::cout << "itemCnt = " << itemCount << '\n';

    if (result) {
        // Todo: 日志
        std::cout << "query error!" << '\n';
    }

    return resVec;
}

void closeSqliteDB(sqlite3* db) { sqlite3_close(db); }

int queryPinyinCallback(void* data, int argc, char** argv, char** azColName) {
    UserData* userData = static_cast<UserData*>(data);
    std::vector<std::pair<std::string, long>>& myVec = userData->result;
    myVec.push_back(std::make_pair(std::string(argv[1]), std::stol(argv[2])));
    userData->itemCount++;
    return 0;
}

int main(int argc, char const* argv[]) {
    std::string dbPath = "../../src/flyciku.db";
    sqlite3* db = openSqlite(dbPath);
    std::vector<std::pair<std::string, long>> resVec = queryPinyin(db, "a");
    queryPinyin(db, "aa");
    queryPinyin(db, "ni");
    queryPinyin(db, "wo");
    queryPinyin(db, "gw");
    // for (auto eachPair : resVec) {
    //     std::cout << eachPair.first << "\t" << eachPair.second << '\n';
    // }
    closeSqliteDB(db);
    return 0;
}
