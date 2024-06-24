const { contextBridge, ipcRenderer } = require('electron')
contextBridge.exposeInMainWorld('electronAPI', {
    DoubleOpenFolder: (number) => ipcRenderer.send('OpenFolder', number),
    indexRightSelect:(number) => ipcRenderer.send('rightSelect',number),
    Querydata:(file_name) => ipcRenderer.send("Queryfile_name",file_name),
    callbackQuerydata:(callback) =>ipcRenderer.on("file_data_send",(_event, value) => callback(value))
})