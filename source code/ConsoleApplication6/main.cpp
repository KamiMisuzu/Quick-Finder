#include "main.h"

//#pragma comment(linker, "/entry:main") 


int WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nCmdShow)
{
    vector<TexT> disk_set = ToolDisk::GetLocalDiskName(false);
    AirFIleSystem* fileststem = new AirFIleSystem(disk_set);
    string cmdLine(lpCmdLine);
    istringstream iss(cmdLine);
    queue<string> args;
    string arg;

    while (iss >> arg) {
        args.push(arg);
    }
    int select_number = stoi(args.front());
    args.pop();
    switch (select_number)
    {
    case 1:
        fileststem->GetFileSystem();
        break;
    case 2:
        fileststem->SelectFile(args.front());
        break;
    default:
        break;
    }
    

    return 0;
    /*string cmdLine(lpCmdLine);*/

    
    //std::istringstream iss(cmdLine);
    //std::vector<std::string> args;
    //std::string arg;
    //while (iss >> arg) {
    //    args.push_back(arg);
    //}

    //// 打印所有的参数
    //for (const auto& a : args) {
    //    MessageBoxA(NULL, a.c_str(), "Argument", MB_OK);
    //}
}