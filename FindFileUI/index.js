// var fileSetof = [
//     {
//         "number":1,
//       "fileName": "example.txt",
//       "filePath": "/path/to/example.txt",
//       "fileSize": 1024,
//       "fileType": "text/plain",
//       "lastModified": "2024-06-04T12:00:00Z"
//     },
//     {
//         "number":2,
//       "fileName": "document.docx",
//       "filePath": "/documents/report/document.docx",
//       "fileSize": 2048,
//       "fileType": "application/vnd.openxmlformats-officedocument.wordprocessingml.document",
//       "lastModified": "2024-06-03T09:30:00Z"
//     },
//     {
//         "number":3,
//       "fileName": "1.png",
//       "filePath": "C:\\Users\\Administrator\\Pictures\\1.png",
//       "fileSize": 4096,
//       "fileType": "image/jpeg",
//       "lastModified": "2024-06-02T15:45:00Z"
//     },
//     {
//         "number":4,
//       "fileName": "spreadsheet.xlsx",
//       "filePath": "/documents/finance/spreadsheet.xlsx",
//       "fileSize": 8192,
//       "fileType": "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet",
//       "lastModified": "2024-06-01T11:20:00Z"
//     },
//     {
//       "number":5,
//       "fileName": "code.js",
//       "filePath": "/projects/code/code.js",
//       "fileSize": 512,
//       "fileType": "application/javascript",
//       "lastModified": "2024-05-31T14:10:00Z"
//     },
//     {
//         "number":6,
//       "fileName": "presentation.pptx",
//       "filePath": "/documents/documents/presentation.pptx",
//       "fileSize": 16384,
//       "fileType": "application/vnd.openxmlformats-officedocument.presentationml.presentation",
//       "lastModified": "2024-05-30T16:50:00Z"
//     },
//     {
//         "number":7,
//       "fileName": "archive.zip",
//       "filePath": "/backup/archive.zip",
//       "fileSize": 32768,
//       "fileType": "application/zip",
//       "lastModified": "2024-05-29T17:15:00Z"
//     },
//     {
//         "number":8,
//       "fileName": "video.mp4",
//       "filePath": "/media/video/video.mp4",
//       "fileSize": 65536,
//       "fileType": "video/mp4",
//       "lastModified": "2024-05-28T18:30:00Z"
//     },
//     {
//         "number":9,
//       "fileName": "presentation.ppt",
//       "filePath": "/d/presentation/presentation.ppt",
//       "fileSize": 10240,
//       "fileType": "application/vnd.ms-powerpoint",
//       "lastModified": "2024-05-27T19:45:00Z"
//     },
//     {
//         "number":10,
//       "fileName": "audio.mp3",
//       "filePath": "/media/audio/audio.mp3",
//       "fileSize": 20480,
//       "fileType": "audio/mpeg",
//       "lastModified": "2024-05-26T20:00:00Z"
//     }
//   ]


const Foldericon = `<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 24 24"><path fill="#DAA520" d="M4 20q-.825 0-1.412-.587T2 18V6q0-.825.588-1.412T4 4h6l2 2h8q.825 0 1.413.588T22 8v10q0 .825-.587 1.413T20 20z"/></svg>`
const TxtIcon = `<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 24 24"><path fill="#cccccc" d="M18.385 18h-9.77q-.69 0-1.152-.462T7 16.384V3.616q0-.691.463-1.153T8.616 2H15.5L20 6.5v9.885q0 .69-.462 1.153T18.384 18M15 7V3H8.616q-.231 0-.424.192T8 3.616v12.769q0 .23.192.423t.423.192h9.77q.23 0 .423-.192t.192-.424V7zM4.616 22q-.691 0-1.153-.462T3 20.385V8h1v12.385q0 .23.192.423t.423.192H14v1zM8 3v4zv14z"/></svg>`
const CsvIcon = `<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 15 15"><path fill="#e11d48" d="M13.5 3.5h.5v-.207l-.146-.147zm-3-3l.354-.354L10.707 0H10.5zm-4 6V6H6v.5zm0 2H6V9h.5zm2 0H9V8h-.5zm0 2v.5H9v-.5zm2-1H10v.207l.146.147zm1 1l-.354.354l.354.353l.354-.353zm1-1l.354.354l.146-.147V9.5zm-10-3V6H2v.5zm0 4H2v.5h.5zM2 5V1.5H1V5zm11-1.5V5h1V3.5zM2.5 1h8V0h-8zm7.646-.146l3 3l.708-.708l-3-3zM2 1.5a.5.5 0 0 1 .5-.5V0A1.5 1.5 0 0 0 1 1.5zM1 12v1.5h1V12zm1.5 3h10v-1h-10zM14 13.5V12h-1v1.5zM12.5 15a1.5 1.5 0 0 0 1.5-1.5h-1a.5.5 0 0 1-.5.5zM1 13.5A1.5 1.5 0 0 0 2.5 15v-1a.5.5 0 0 1-.5-.5zM9 6H6.5v1H9zm-3 .5v2h1v-2zM6.5 9h2V8h-2zM8 8.5v2h1v-2zm.5 1.5H6v1h2.5zM10 6v3.5h1V6zm.146 3.854l1 1l.708-.708l-1-1zm1.708 1l1-1l-.708-.708l-1 1zM13 9.5V6h-1v3.5zM5 6H2.5v1H5zm-3 .5v4h1v-4zm.5 4.5H5v-1H2.5z"/></svg>`
const DockIcon = `<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 16 16"><path fill="#db2777" fill-rule="evenodd" d="M14 4.5V11h-1V4.5h-2A1.5 1.5 0 0 1 9.5 3V1H4a1 1 0 0 0-1 1v9H2V2a2 2 0 0 1 2-2h5.5zm-6.839 9.688v-.522a1.5 1.5 0 0 0-.117-.641a.86.86 0 0 0-.322-.387a.86.86 0 0 0-.469-.129a.87.87 0 0 0-.471.13a.87.87 0 0 0-.32.386a1.5 1.5 0 0 0-.117.641v.522q0 .384.117.641a.87.87 0 0 0 .32.387a.9.9 0 0 0 .471.126a.9.9 0 0 0 .469-.126a.86.86 0 0 0 .322-.386a1.55 1.55 0 0 0 .117-.642m.803-.516v.513q0 .563-.205.973a1.47 1.47 0 0 1-.589.627q-.381.216-.917.216a1.86 1.86 0 0 1-.92-.216a1.46 1.46 0 0 1-.589-.627a2.15 2.15 0 0 1-.205-.973v-.513q0-.569.205-.975q.205-.411.59-.627q.386-.22.92-.22q.535 0 .916.22q.383.219.59.63q.204.406.204.972M1 15.925v-3.999h1.459q.609 0 1.005.235q.396.233.589.68q.196.445.196 1.074q0 .634-.196 1.084q-.197.451-.595.689q-.396.237-.999.237zm1.354-3.354H1.79v2.707h.563q.277 0 .483-.082a.8.8 0 0 0 .334-.252q.132-.17.196-.422a2.3 2.3 0 0 0 .068-.592q0-.45-.118-.753a.9.9 0 0 0-.354-.454q-.237-.152-.61-.152Zm6.756 1.116q0-.373.103-.633a.87.87 0 0 1 .301-.398a.8.8 0 0 1 .475-.138q.225 0 .398.097a.7.7 0 0 1 .273.26a.85.85 0 0 1 .12.381h.765v-.073a1.33 1.33 0 0 0-.466-.964a1.4 1.4 0 0 0-.49-.272a1.8 1.8 0 0 0-.606-.097q-.534 0-.911.223q-.375.222-.571.633q-.197.41-.197.978v.498q0 .568.194.976q.195.406.571.627q.375.216.914.216q.44 0 .785-.164t.551-.454a1.27 1.27 0 0 0 .226-.674v-.076h-.765a.8.8 0 0 1-.117.364a.7.7 0 0 1-.273.248a.9.9 0 0 1-.401.088a.85.85 0 0 1-.478-.131a.83.83 0 0 1-.298-.393a1.7 1.7 0 0 1-.103-.627zm5.092-1.76h.894l-1.275 2.006l1.254 1.992h-.908l-.85-1.415h-.035l-.852 1.415h-.862l1.24-2.015l-1.228-1.984h.932l.832 1.439h.035z"/></svg>`
const PdfIcon = `<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 24 24"><g fill="none" stroke="#db2777" stroke-linecap="round" stroke-linejoin="round" stroke-width="1.5" color="#db2777"><path d="M7 18v-2.5m0 0V14c0-.471 0-.707.154-.854C7.308 13 7.555 13 8.05 13h.7c.725 0 1.313.56 1.313 1.25S9.475 15.5 8.75 15.5zM21 13h-1.312c-.825 0-1.238 0-1.494.244s-.256.637-.256 1.423v.833m0 2.5v-2.5m0 0h2.187m-4.375 0c0 1.38-1.175 2.5-2.625 2.5c-.327 0-.49 0-.613-.067c-.291-.16-.262-.485-.262-.766v-3.334c0-.281-.03-.606.262-.766c.122-.067.286-.067.613-.067c1.45 0 2.625 1.12 2.625 2.5"/><path d="M15 22h-4.273c-3.26 0-4.892 0-6.024-.798a4.1 4.1 0 0 1-.855-.805C3 19.331 3 17.797 3 14.727v-2.545c0-2.963 0-4.445.469-5.628c.754-1.903 2.348-3.403 4.37-4.113C9.095 2 10.668 2 13.818 2c1.798 0 2.698 0 3.416.252c1.155.406 2.066 1.263 2.497 2.35C20 5.278 20 6.125 20 7.818V10"/><path d="M3 12a3.333 3.333 0 0 1 3.333-3.333c.666 0 1.451.116 2.098-.057A1.67 1.67 0 0 0 9.61 7.43c.173-.647.057-1.432.057-2.098A3.333 3.333 0 0 1 13 2"/></g></svg>`
const Mp3Icon =`<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 16 16"><path fill="#db2777" fill-rule="evenodd" d="M14 4.5V14a2 2 0 0 1-2 2v-1a1 1 0 0 0 1-1V4.5h-2A1.5 1.5 0 0 1 9.5 3V1H4a1 1 0 0 0-1 1v9H2V2a2 2 0 0 1 2-2h5.5zm-4.911 9.67h-.443v-.609h.422a.7.7 0 0 0 .322-.073a.56.56 0 0 0 .22-.2a.5.5 0 0 0 .076-.284a.49.49 0 0 0-.176-.392a.65.65 0 0 0-.442-.15a.7.7 0 0 0-.252.041a.6.6 0 0 0-.193.112a.5.5 0 0 0-.179.349H7.71q.009-.235.102-.437q.094-.202.27-.352q.176-.152.428-.237q.255-.085.583-.088q.418-.003.723.132q.304.135.472.372a.9.9 0 0 1 .173.539a.83.83 0 0 1-.12.478a.96.96 0 0 1-.619.439v.041a1 1 0 0 1 .718.434a.9.9 0 0 1 .144.521q.003.285-.117.507a1.1 1.1 0 0 1-.329.378q-.21.152-.486.234q-.273.08-.583.08q-.451 0-.77-.153a1.2 1.2 0 0 1-.487-.41a1.1 1.1 0 0 1-.178-.563h.726a.46.46 0 0 0 .106.258a.7.7 0 0 0 .249.179a1 1 0 0 0 .357.067a.9.9 0 0 0 .384-.076a.6.6 0 0 0 .252-.217a.56.56 0 0 0 .088-.319a.56.56 0 0 0-.334-.522a.8.8 0 0 0-.372-.079ZM.706 15.925v-2.66h.038l.952 2.16h.516l.946-2.16h.038v2.66h.715v-3.999h-.8l-1.14 2.596h-.026l-1.14-2.596H0v4zm5.458-3.999h-1.6v4h.792v-1.342h.803q.43 0 .732-.173q.304-.177.463-.475a1.4 1.4 0 0 0 .161-.677q0-.374-.158-.677a1.2 1.2 0 0 0-.46-.477a1.4 1.4 0 0 0-.733-.179m.545 1.333a.8.8 0 0 1-.085.381a.57.57 0 0 1-.237.24a.8.8 0 0 1-.375.082h-.66v-1.406h.66q.328 0 .513.182q.184.181.184.521"/></svg>`
const AacIcon=`<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 16 16"><path fill="#db2777" fill-rule="evenodd" d="M14 4.5V14a2 2 0 0 1-2 2v-1a1 1 0 0 0 1-1V4.5h-2A1.5 1.5 0 0 1 9.5 3V1H4a1 1 0 0 0-1 1v9H2V2a2 2 0 0 1 2-2h5.5zm-5.808 8.554a1.7 1.7 0 0 0-.103.633v.495q0 .369.103.627a.83.83 0 0 0 .299.393a.85.85 0 0 0 .477.131a.9.9 0 0 0 .402-.088a.7.7 0 0 0 .272-.248a.8.8 0 0 0 .117-.364h.765v.076a1.27 1.27 0 0 1-.226.674q-.204.29-.55.454a1.8 1.8 0 0 1-.785.164q-.54 0-.915-.216a1.4 1.4 0 0 1-.57-.627q-.195-.408-.194-.976v-.498q0-.568.196-.978q.195-.411.571-.633q.378-.223.912-.223q.327 0 .606.097q.28.093.49.272a1.33 1.33 0 0 1 .465.964v.073h-.765a.85.85 0 0 0-.12-.38a.7.7 0 0 0-.272-.261a.8.8 0 0 0-.399-.097a.8.8 0 0 0-.474.138a.87.87 0 0 0-.302.398M.8 15.925l.313-1.028H2.45l.314 1.028h.84l-1.335-3.999h-.926l-1.342 4zm1.002-3.234l.489 1.617H1.277l.49-1.617zm2.63 3.234l.313-1.028H6.08l.313 1.028h.841L5.9 11.926h-.926l-1.341 4zm1.001-3.234l.49 1.617H4.909l.49-1.617z"/></svg>`
const oggIcon = `<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 24 24"><path fill="#0284c7" d="M10.75 19q.95 0 1.6-.65t.65-1.6V13h3v-2h-4v3.875q-.275-.2-.587-.288t-.663-.087q-.95 0-1.6.65t-.65 1.6t.65 1.6t1.6.65M6 22q-.825 0-1.412-.587T4 20V4q0-.825.588-1.412T6 2h8l6 6v12q0 .825-.587 1.413T18 22zm7-13V4H6v16h12V9zM6 4v5zv16z"/></svg>`
const Mp4Icon = `<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 15 15"><path fill="#0284c7" d="M7 8h.5a.5.5 0 0 0 0-1H7z"/><path fill="#0284c7" fill-rule="evenodd" d="M1 1.5A1.5 1.5 0 0 1 2.5 0h8.207L14 3.293V13.5a1.5 1.5 0 0 1-1.5 1.5h-10A1.5 1.5 0 0 1 1 13.5zM6 6h1.5a1.5 1.5 0 1 1 0 3H7v2H6zm-3.691.038a.5.5 0 0 1 .545.108l.646.647l.646-.647A.5.5 0 0 1 5 6.5V11H4V7.707l-.5.5l-.5-.5V11H2V6.5a.5.5 0 0 1 .309-.462M11 6h-1v3h2v2h1V6h-1v2h-1z" clip-rule="evenodd"/></svg>`
const aviIcon =`<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 24 24"><g fill="none" stroke="#0284c7" stroke-linecap="round" stroke-width="1.5"><path stroke-linejoin="round" d="m12 9l1.5 6L15 9m3 6V9"/><path d="M4 6V3.6a.6.6 0 0 1 .6-.6h14.8a.6.6 0 0 1 .6.6V6M4 18v2.4a.6.6 0 0 0 .6.6h14.8a.6.6 0 0 0 .6-.6V18"/><path stroke-linejoin="round" d="M6 15v-3m0 0v-1.5A1.5 1.5 0 0 1 7.5 9v0A1.5 1.5 0 0 1 9 10.5V12m-3 0h3m0 0v3"/></g></svg>`
const videoIcon =`<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 24 24"><path fill="#0284c7" d="m11.5 14.5l7-4.5l-7-4.5zM8 18q-.825 0-1.412-.587T6 16V4q0-.825.588-1.412T8 2h12q.825 0 1.413.588T22 4v12q0 .825-.587 1.413T20 18zm-4 4q-.825 0-1.412-.587T2 20V6h2v14h14v2z"/></svg>`
const xlsxIcon = `<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 16 16"><path fill="#0284c7" fill-rule="evenodd" d="M14 4.5V11h-1V4.5h-2A1.5 1.5 0 0 1 9.5 3V1H4a1 1 0 0 0-1 1v9H2V2a2 2 0 0 1 2-2h5.5zM7.86 14.841a1.13 1.13 0 0 0 .401.823q.195.162.479.252q.284.091.665.091q.507 0 .858-.158q.355-.158.54-.44a1.17 1.17 0 0 0 .187-.656q0-.336-.135-.56a1 1 0 0 0-.375-.357a2 2 0 0 0-.565-.21l-.621-.144a1 1 0 0 1-.405-.176a.37.37 0 0 1-.143-.299q0-.234.184-.384q.188-.152.513-.152q.214 0 .37.068a.6.6 0 0 1 .245.181a.56.56 0 0 1 .12.258h.75a1.1 1.1 0 0 0-.199-.566a1.2 1.2 0 0 0-.5-.41a1.8 1.8 0 0 0-.78-.152q-.44 0-.777.15q-.336.149-.527.421q-.19.273-.19.639q0 .302.123.524t.351.367q.229.143.54.213l.618.144q.31.073.462.193a.39.39 0 0 1 .153.326a.5.5 0 0 1-.085.29a.56.56 0 0 1-.255.193q-.168.07-.413.07q-.176 0-.32-.04a.8.8 0 0 1-.249-.115a.58.58 0 0 1-.255-.384zm-3.726-2.909h.893l-1.274 2.007l1.254 1.992h-.908l-.85-1.415h-.035l-.853 1.415H1.5l1.24-2.016l-1.228-1.983h.931l.832 1.438h.036zm1.923 3.325h1.697v.674H5.266v-3.999h.791zm7.636-3.325h.893l-1.274 2.007l1.254 1.992h-.908l-.85-1.415h-.035l-.853 1.415h-.861l1.24-2.016l-1.228-1.983h.931l.832 1.438h.036z"/></svg>`
const exeIcon = `<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 32 32"><path fill="#0284c7" fill-rule="evenodd" d="m25 21l7 5l-7 5z"/><path fill="#0284c7" d="m20.17 19l-2.59 2.59L19 23l4-4l-4-4l-1.42 1.41zm-8.34 0l2.59-2.59L13 15l-4 4l4 4l1.42-1.41z"/><circle cx="9" cy="8" r="1" fill="#0284c7"/><circle cx="6" cy="8" r="1" fill="#0284c7"/><path fill="#0284c7" d="M21 26H4V12h24v7h2V6c0-1.102-.897-2-2-2H4c-1.103 0-2 .898-2 2v20c0 1.103.897 2 2 2h17zM4 6h24v4H4z"/></svg>`
const pptIcon = `<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 256 256"><path fill="#0284c7" d="M224 152.53a8.17 8.17 0 0 1-8.25 7.47H204v47.73a8.17 8.17 0 0 1-7.47 8.25a8 8 0 0 1-8.53-8V160h-11.73a8.17 8.17 0 0 1-8.25-7.47a8 8 0 0 1 8-8.53h40a8 8 0 0 1 7.98 8.53M92 172.85C91.54 188.08 78.64 200 63.4 200H56v7.73a8.17 8.17 0 0 1-7.47 8.27a8 8 0 0 1-8.53-8v-56a8 8 0 0 1 8-8h16a28 28 0 0 1 28 28.85m-16-2A12.25 12.25 0 0 0 63.65 160H56v24h8a12 12 0 0 0 12-13.16Zm84 2c-.46 15.23-13.36 27.15-28.6 27.15H124v7.73a8.17 8.17 0 0 1-7.47 8.25a8 8 0 0 1-8.53-8V152a8 8 0 0 1 8-8h16a28 28 0 0 1 28 28.85m-16-2A12.25 12.25 0 0 0 131.65 160H124v24h8a12 12 0 0 0 12-13.16ZM40 116V40a16 16 0 0 1 16-16h96a8 8 0 0 1 5.66 2.34l56 56A8 8 0 0 1 216 88v28a4 4 0 0 1-4 4H44a4 4 0 0 1-4-4m112-28h44l-44-44Z"/></svg>`
const jsIcon =`<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 256 256"><path fill="#F7DF1E" d="M0 0h256v256H0z"/><path d="m67.312 213.932l19.59-11.856c3.78 6.701 7.218 12.371 15.465 12.371c7.905 0 12.89-3.092 12.89-15.12v-81.798h24.057v82.138c0 24.917-14.606 36.259-35.916 36.259c-19.245 0-30.416-9.967-36.087-21.996m85.07-2.576l19.588-11.341c5.157 8.421 11.859 14.607 23.715 14.607c9.969 0 16.325-4.984 16.325-11.858c0-8.248-6.53-11.17-17.528-15.98l-6.013-2.58c-17.357-7.387-28.87-16.667-28.87-36.257c0-18.044 13.747-31.792 35.228-31.792c15.294 0 26.292 5.328 34.196 19.247l-18.732 12.03c-4.125-7.389-8.591-10.31-15.465-10.31c-7.046 0-11.514 4.468-11.514 10.31c0 7.217 4.468 10.14 14.778 14.608l6.014 2.577c20.45 8.765 31.963 17.7 31.963 37.804c0 21.654-17.012 33.51-39.867 33.51c-22.339 0-36.774-10.654-43.819-24.574"/></svg>`
const pyIcon = `<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 256 256"><g fill="none"><rect width="256" height="256" fill="#F4F2ED" rx="60"/><path fill="url(#IconifyId18fe77393dd5eee6f0)" d="M127.279 29c-50.772 0-47.602 22.018-47.602 22.018l.057 22.81h48.451v6.85H60.489S28 76.992 28 128.221c0 51.23 28.357 49.414 28.357 49.414h16.924v-23.773s-.912-28.357 27.905-28.357h48.054s26.999.436 26.999-26.094V55.546S180.338 29 127.279 29m-26.716 15.339a8.708 8.708 0 0 1 8.717 8.717a8.708 8.708 0 0 1-8.717 8.716a8.708 8.708 0 0 1-8.716-8.716a8.708 8.708 0 0 1 8.716-8.717"/><path fill="url(#IconifyId18fe77393dd5eee6f1)" d="M128.721 227.958c50.772 0 47.602-22.017 47.602-22.017l-.057-22.811h-48.451v-6.849h67.696S228 179.966 228 128.736c0-51.23-28.357-49.413-28.357-49.413h-16.924v23.773s.912 28.357-27.905 28.357H106.76s-27-.437-27 26.093v43.866s-4.099 26.546 48.961 26.546m26.716-15.339a8.708 8.708 0 0 1-8.717-8.716a8.708 8.708 0 0 1 8.717-8.717a8.709 8.709 0 0 1 8.717 8.717a8.709 8.709 0 0 1-8.717 8.716"/><defs><linearGradient id="IconifyId18fe77393dd5eee6f0" x1="47.22" x2="146.333" y1="46.896" y2="145.02" gradientUnits="userSpaceOnUse"><stop stop-color="#387EB8"/><stop offset="1" stop-color="#366994"/></linearGradient><linearGradient id="IconifyId18fe77393dd5eee6f1" x1="108.056" x2="214.492" y1="109.905" y2="210.522" gradientUnits="userSpaceOnUse"><stop stop-color="#FFE052"/><stop offset="1" stop-color="#FFC331"/></linearGradient></defs></g></svg>`
const zipIcon = `<svg xmlns="http://www.w3.org/2000/svg" width="128" height="128" viewBox="0 0 24 24"><path fill="#0284c7" d="M14 17h-2v-2h-2v-2h2v2h2m0-6h-2v2h2v2h-2v-2h-2V9h2V7h-2V5h2v2h2m5-4H5c-1.11 0-2 .89-2 2v14a2 2 0 0 0 2 2h14a2 2 0 0 0 2-2V5a2 2 0 0 0-2-2"/></svg>`
const imgIcon = ['jpg','png','svg','jpeg','bmp','webp']




function SelectIcon(Posterior) {
  var icon = null;
  switch (Posterior) {
    case "txt":
      icon=TxtIcon
      break
    case "csv":
      icon=CsvIcon
    case "docx":
    case "doc":
      icon = DockIcon
      break
    case "xlsx":
      icon =xlsxIcon
      break
    case "pdf":
      icon = PdfIcon
      break
    case "mp3":
      icon = Mp3Icon
      break
    case "aac":
      icon = AacIcon
      break
    case "ogg":
    case "flac":
    case "wav":
    case "alac":
      icon = oggIcon
      break
    case "mp4":
      icon = Mp4Icon
      break
    case "mov":
    case "divx":
    case "mpeg":
    case "mkv":
    case "asf":
      icon = videoIcon
      break
    case "exe":
      icon =exeIcon
      break
    case "ppt":
    case "pptx":
     icon = pptIcon
     break
    case "js":
      icon =jsIcon
      break
    case "py":
      icon = pyIcon
      break
    case "zip":
    case  "rar":
    case  "arj":
    case  "jar":
    case  "gz":
    case  "7z":
      icon= zipIcon
      break
    default:
      icon=Foldericon
    }
  return icon
  }

const MouseClick = {
  indexDoubleOpenFolder : (e)=>{
    window.electronAPI.DoubleOpenFolder(e)
},
  indexRightSelect:(e) =>{
    window.electronAPI.indexRightSelect(e)
  },
  Querydata_file:(e)=>{
    window.electronAPI.Querydata(e.value)
  }
}
// oncontextmenu=""
function addFileHtml(fileSetofetof){
  var fileDom = document.getElementById('showFileList')
  let i = 0;
  for (i=0;i < fileSetofetof.length; i++) {
    try {
      let iconSelect = fileSetofetof[i].fileName.split('.').pop()
      var icon;
      if (imgIcon.includes(iconSelect)) {
        icon = `<img src="${fileSetof[i].filePath}" alt="">`
      }else{
        icon = SelectIcon(iconSelect)
      }
      let file_path = fileSetofetof[i].filePath.replace(/\\/g, '\\\\');
  fileDom.innerHTML += `<div id="file-${i}" ondblclick="MouseClick.indexDoubleOpenFolder('${file_path}')" oncontextmenu="MouseClick.indexRightSelect('${file_path}')">${icon}<div id="filename">${fileSetofetof[i].fileName}</div> <div id="filePath">${fileSetofetof[i].filePath}</div> <div id="updateTime">最后打开日期:${fileSetofetof[i].lastModified}</div></div>`;

      
    } catch (error) {
      continue
    }
  }
}
function SetEventListenerEve(fileSetofetof){
  let i = 0;
  for (i=0;i < fileSetofetof.length; i++) {
    try {
      
    
    var temp = document.getElementById(`file-${i}`)
    temp.addEventListener('click',function(e){
      var id = e.target.closest('div[id^="file-"]').id.split('-')[1]
      var attrbody = document.getElementById("attribute")
      var iconSelect = fileSetofetof[id].fileName.split('.').pop()
      var icon;
      if (imgIcon.includes(iconSelect)) {
        icon = `<img src="${fileSetof[id].filePath}" alt="">`
      }else{
        icon = SelectIcon(iconSelect)
      }
      attrbody.innerHTML=`
      <div id="attributeFileIcon">
      ${icon}
      </div><div id="showFileName">文件名:${fileSetof[id].fileName}</div>
      <div id="showFileName">文件路径:${fileSetof[id].filePath}</div>
      <div id="showFileName">文件大小:${fileSetof[id].fileSize/1024}M</div>`
      
  })} catch (error) {
      
  }
  }
}


var key = 1

const inputElement = document.getElementById("SearchInput");
inputElement.addEventListener("keydown",()=>{
  if (event.keyCode !== 13) return
  if (inputElement.value == "") {
    return false;
  }
  MouseClick.Querydata_file(inputElement);
})
window.electronAPI.callbackQuerydata((value) => {
  fileSetof = [];
  
    for (let index = 0; index < value.length; index++) {
      let separte = value[index].split("&")
      var fileObject = {
        "fileName": separte[1],
        "filePath":separte[0],
        "fileSize": 0,
        "lastModified": "0"
        }
        fileSetof.push(fileObject)
    }
    addFileHtml(fileSetof)
    SetEventListenerEve(fileSetof)
})

 


