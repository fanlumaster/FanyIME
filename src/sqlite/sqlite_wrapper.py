import sqlite3
import os.path


def openSqlite():
    db_path = os.path.join(os.path.dirname(__file__), "../flyciku.db")
    conn = sqlite3.connect(db_path)
    return conn


def querySinglePinyin(pinyin: str, conn: sqlite3.Connection):
    cursor = conn.cursor()
    tbl_name = "fullpinyinsimple"
    query_var = f"""'{pinyin}%'"""
    query = f"select * from {tbl_name} where key like {query_var} and length(key) == 2 order by weight desc"
    result = cursor.execute(query)
    count = len(result.fetchall())
    print(count)

def queryMultiPinyin(pinyin: str, conn: sqlite3.Connection):
    cursor = conn.cursor()
    tbl_name = "fullpinyinsimple"
    query_var = f"""'{pinyin}%'"""
    query = f"select * from {tbl_name} where key like {query_var} and length(key) > 2 order by weight desc limit 20"
    result = cursor.execute(query)
    count = len(result.fetchall())
    print(count)

def closeSqlite(conn: sqlite3.Connection):
    conn.close()


if __name__ == "__main__":
    conn = openSqlite()
    # 如果是一个字符的话，那么，只能取单字
    # 其实对于单字的话，5 * 8 个或许也就够了？
    # querySinglePinyin("a", conn)
    # querySinglePinyin("b", conn)
    # querySinglePinyin("c", conn)
    # querySinglePinyin("d", conn)
    # querySinglePinyin("e", conn)
    # querySinglePinyin("f", conn)
    # querySinglePinyin("g", conn)
    # querySinglePinyin("h", conn)
    # querySinglePinyin("i", conn)
    # querySinglePinyin("j", conn)
    # querySinglePinyin("k", conn)
    # querySinglePinyin("l", conn)
    # querySinglePinyin("m", conn)
    # querySinglePinyin("n", conn)
    # querySinglePinyin("o", conn)
    # querySinglePinyin("p", conn)
    # querySinglePinyin("q", conn)
    # querySinglePinyin("r", conn)
    # querySinglePinyin("s", conn)
    # querySinglePinyin("t", conn)
    # querySinglePinyin("u", conn)
    # querySinglePinyin("v", conn)
    # querySinglePinyin("w", conn)
    # querySinglePinyin("x", conn)
    # querySinglePinyin("y", conn)
    # querySinglePinyin("z", conn)
    querySinglePinyin("zi", conn)
    querySinglePinyin("ji", conn)
    querySinglePinyin("wo", conn)
    querySinglePinyin("gw", conn)
    print("fany split =======")
    queryMultiPinyin("nih", conn)
    queryMultiPinyin("wou", conn)
    queryMultiPinyin("woui", conn)
    closeSqlite(conn)
