//#include <windows.h>
//#include <winioctl.h>
//#include <iostream>
//#include <vector>
//
//#pragma comment(lib, "ntdll.lib")
//#define BUF_LEN 4096  
//int main() {
//
//    HANDLE hVolume = CreateFile(
//        L"\\\\.\\C:", // Volume to query, change to the appropriate volume
//        GENERIC_READ | GENERIC_WRITE,
//        FILE_SHARE_READ | FILE_SHARE_WRITE,
//        NULL,
//        OPEN_EXISTING,
//        0,
//        NULL
//    );
//    CHAR buffer[BUF_LEN]; // 用于储存记录的缓冲 , 尽量足够地大  
//
//    DWORD usnDataSize;
//
//    PUSN_RECORD UsnRecord;
//    MFT_ENUM_DATA_V0 med = { 0 };
//    while (0 != DeviceIoControl(hVolume,
//        FSCTL_ENUM_USN_DATA,
//        &med,
//        sizeof(med),
//        buffer,
//        BUF_LEN,
//        &usnDataSize,
//        NULL))
//    {
//
//        DWORD dwRetBytes = usnDataSize - sizeof(USN);
//        UsnRecord = (PUSN_RECORD)(((PCHAR)buffer) + sizeof(USN));
//
//        //printf(" ********************************** \n");
//
//        while (dwRetBytes > 0) {
//
//            // 打印获取到的信息  
//            const int strLen = UsnRecord->FileNameLength;
//            char fileName[MAX_PATH] = { 0 };
//            WideCharToMultiByte(CP_OEMCP, NULL, UsnRecord->FileName, strLen / 2, fileName, strLen, NULL, FALSE);
//
//            //printf("FileName: %s\n", fileName);
//            // 下面两个 file reference number 可以用来获取文件的路径信息  
//  /*          printf("FileReferenceNumber: %xI64\n", UsnRecord->FileReferenceNumber);
//            printf("ParentFileReferenceNumber: %xI64\n", UsnRecord->ParentFileReferenceNumber);
//            printf("\n");*/
//
//            DWORD recordLen = UsnRecord->RecordLength;
//            dwRetBytes -= recordLen;
//            UsnRecord = (PUSN_RECORD)(((PCHAR)UsnRecord) + recordLen);
//
//        }
//
//        med.StartFileReferenceNumber = *(USN*)&buffer;
//
//    }
//}
