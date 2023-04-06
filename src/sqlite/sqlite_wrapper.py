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


def queryTwoPinyin(pinyin: str, conn: sqlite3.Connection):
    cursor = conn.cursor()
    tbl_name = "fullpinyinsimple"
    query_var = f"""'{pinyin}%'"""
    query = f"select * from {tbl_name} where key like {query_var} and length(key) == 4 order by weight desc limit 200"
    result = cursor.execute(query)
    # count = len(result.fetchall())
    for each in result.fetchall():
        print(each)


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
    queryTwoPinyin("nihc", conn)
    closeSqlite(conn)
