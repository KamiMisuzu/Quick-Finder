const {shell} = require('electron')


function OpenFolder(path){
    shell.openPath(path)
}
function OpenFile(path){
    shell.openPath(path)
}


function removeAfterLastCharacter(str, char) {
    // 找到最后一个特定字符的位置
    const lastIndex = str.lastIndexOf(char);
    if (lastIndex !== -1) {
        return str.substring(0, lastIndex);
    }
    return str;
}


module.exports = {OpenFolder,OpenFile,removeAfterLastCharacter}
