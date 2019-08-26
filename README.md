# HappyCampShapeDP

## File System

![](https://i.imgur.com/StRCrap.jpg)
* 以下功能請全部撰寫單元測試，驗證功能無誤
* `Directory`內使用**list**儲存`DirectoryElement`。
* `TxtFile`和`Mp3File`建構的時候需傳入檔名(不包含副檔名)及檔案大小，`Directory`則傳入目錄的名字。 
* **findDirectoryElement(string)**為傳入關鍵字並尋找檔案或目錄，若找得到名稱完全相同的檔案(包含副檔名)或目錄則回傳之，若找不到則回傳`nullptr`。 
* 其他未說明的項目請參考測試案例。 
* `.cpp`檔和`.h`檔請分開。
* 在單元測試產生instance時，請使用上課所教的simple factory or class factory去產生相對應的instance, 不能使用new去創建instance.
![](https://i.imgur.com/4EbDRvN.png)
