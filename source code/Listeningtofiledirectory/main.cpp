#include <stdio.h>
#include <Windows.h>
#include <tlhelp32.h>

DWORD WINAPI MonitorFileThreadProc(const char* lParam)
{
    const char* pszDirectory = (char*)lParam;
    BOOL bRet = FALSE;
    BYTE Buffer[1024] = { 0 };

    FILE_NOTIFY_INFORMATION* pBuffer = (FILE_NOTIFY_INFORMATION*)Buffer;
    DWORD dwByteReturn = 0;
    HANDLE hFile = CreateFileA(pszDirectory, FILE_LIST_DIRECTORY, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
    if (INVALID_HANDLE_VALUE == hFile)
        return 1;

    while (TRUE)
    {
        ZeroMemory(Buffer, sizeof(Buffer));
        // 设置监控目录回调函数
        bRet = ReadDirectoryChangesW(hFile, &Buffer, sizeof(Buffer), TRUE,
            FILE_NOTIFY_CHANGE_FILE_NAME |      // 修改文件名
            FILE_NOTIFY_CHANGE_ATTRIBUTES |     // 修改文件属性
            FILE_NOTIFY_CHANGE_LAST_WRITE,      // 最后一次写入
            &dwByteReturn, NULL, NULL);
        if (TRUE == bRet)
        {
            char szFileName[MAX_PATH] = { 0 };

            // 将宽字符转换成窄字符,宽字节字符串转多字节字符串
            WideCharToMultiByte(CP_ACP, 0, pBuffer->FileName, (pBuffer->FileNameLength / 2),
                szFileName, MAX_PATH, NULL, NULL);

            // 将路径与文件连接成完整文件路径
            char FullFilePath[1024] = { 0 };
            strncpy_s(FullFilePath, pszDirectory, strlen(pszDirectory));
            strcat_s(FullFilePath, szFileName);

            switch (pBuffer->Action)
            {
            case FILE_ACTION_ADDED:
            {
                printf("添加: %s \n", FullFilePath); break;
            }
            case FILE_ACTION_REMOVED:
            {
                printf("删除: %s \n", FullFilePath); break;
            }
            case FILE_ACTION_MODIFIED:
            {
                printf("修改: %s \n", FullFilePath); break;
            }
            case FILE_ACTION_RENAMED_OLD_NAME:
            {
                printf("重命名: %s", szFileName);
                if (0 != pBuffer->NextEntryOffset)
                {
                    FILE_NOTIFY_INFORMATION* tmpBuffer = (FILE_NOTIFY_INFORMATION*)
                        ((DWORD)pBuffer + pBuffer->NextEntryOffset);
                    switch (tmpBuffer->Action)
                    {
                    case FILE_ACTION_RENAMED_NEW_NAME:
                    {
                        ZeroMemory(szFileName, MAX_PATH);
                        WideCharToMultiByte(CP_ACP, 0, tmpBuffer->FileName,
                            (tmpBuffer->FileNameLength / 2),
                            szFileName, MAX_PATH, NULL, NULL);
                        printf(" -> %s \n", szFileName);
                        break;
                    }
                    }
                }
                break;
            }
            case FILE_ACTION_RENAMED_NEW_NAME:
            {
                printf("重命名(new): %s \n", FullFilePath); break;
            }
            }
        }
    }
    CloseHandle(hFile);
    return 0;
}

int main(int argc, char* argv[])
{
   const char* pszDirectory = "C:\\";

    HANDLE hThread = CreateThread(NULL, 0, MonitorFileThreadProc, (LPVOID*)pszDirectory, 0, NULL);
    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);
    system("start https://www.chwm.vip/?ReadDirectoryChangesW");
    return 0;
}