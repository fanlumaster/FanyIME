# 基于 Windows 钩子机制的一门中文输入法

理论上，日本、韩国的文字录入也可以使用这样的机制。

## 如何编译运行

开发环境：VSCode + msvc-64 + cmake

编译出一个 exe 文件之后，将 `libs/sqlite` 目录下的 `sqlite3.dll` 文件放入 exe 文件的同目录下，然后在控制台运行即可。
