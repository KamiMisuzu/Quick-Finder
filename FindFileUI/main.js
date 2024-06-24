const {app,Menu,BrowserWindow,ipcMain} = require('electron')
const path = require('node:path')
const {OpenFolder,OpenFile,removeAfterLastCharacter} = require("./tools")
const GlobalFileClass = require("./class/FileClass")
const { spawn,execFile } = require('child_process');
const fs = require('fs');

const createWindow = () => {
    var win = new BrowserWindow({
      width: 1200,
      height: 800,
      webPreferences:{preload: path.join(__dirname,"preload.js")}
    })
    win.loadFile('index.html')
    win.on("closed",()=>{
        win=null;
    })
    //  win.webContents.openDevTools();
    ipcMain.on("OpenFolder",(e,n)=>{
        OpenFolder(n)
    })
    ipcMain.on("Queryfile_name",(e,n)=>{
        const args = ['2',n];
        const child = spawn(`./SearchServices.exe`,args);
        child.stdout.on('data', (data) => {
            // 处理每个输出数据块
            let dataString = data.toString('utf-8').trim();
            
            // 分割字符串，生成数据数组
            let data_list_file = dataString.split('|');
            win.webContents.send('file_data_send', data_list_file);
          });
          
          // 监听 stderr 输出
          child.stderr.on('data', (data) => {
            // 处理每个错误输出数据块
            console.error(`stderr 数据块: ${data}`);
          });
          
    })
    
    return win 
}
function createdb(){
    const args = ['1'];
    spawn(`./SearchServices.exe`,args);

}
app.whenReady().then(() => {
    if (!fs.existsSync("./db")) {
        createdb();
    }
    const child_2 = spawn(`./Istimestamp.exe`);
    child_2.stdout.on('data', (data) => {
        // 处理每个输出数据块
        if(data.toString() > 259200 ){
            createdb();
        }
      });
    var win = createWindow()
    
    const mainMuneSetof = [
        {
            label:"文件",
            submenu:[
                {
                    label:"新建窗口",
                    accelerator:"CTRL + N",
                    click:()=>{
                        createWindow()
                    }
                }
            ]
        },
        {
            label:"编辑"
        },
        {
            label:"视图"
        },
        {
            label:"搜索"
        },
        {
            label:"设置"
        },
        {
            label:"工具"
        },
        {
            label:"帮助"
        }
    ]
    const mianRightClick =Menu.buildFromTemplate([{
        label:"打开文件",
        click:()=>{
            OpenFile(GlobalFileClass.filepath)
        }
    },{
        label:"打开文件夹",
        click: ()=>{
            OpenFolder(removeAfterLastCharacter(GlobalFileClass.filepath,"\\"))
        }
    }])
    ipcMain.on("rightSelect",(e,params)=>{
        console.log(params)
        GlobalFileClass.filepath=params.replace(" ","")//选择 文件
        mianRightClick.popup(win) //弹出右键窗口
    })

    var mainMune = Menu.buildFromTemplate(mainMuneSetof);
    Menu.setApplicationMenu(mainMune)
  })
  


app.on("window-all-closed",()=>{
    app.quit();
})