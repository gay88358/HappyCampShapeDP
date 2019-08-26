# HappyCampShapeDP

## File System

![](https://i.imgur.com/StRCrap.jpg)

* `Directory`內使用**list**儲存`DirectoryElement`。
* `TxtFile`和`Mp3File`建構的時候需傳入檔名(不包含副檔名)及檔案大小，`Directory`則傳入目錄的名字。 
* **findDirectoryElement(string)**為傳入關鍵字並尋找檔案或目錄，若找得到名稱完全相同的檔案(包含副檔名)或目錄則回傳之，若找不到則回傳`nullptr`。 
* 請讓所有的測試案皆通過 (`utTxtFile.h`, `utMp3File.h`, `utDirectory.h`)。
* 其他未說明的項目請參考測試案例。 
* `.cpp`檔和`.h`檔請分開。

![](https://i.imgur.com/4EbDRvN.png)
