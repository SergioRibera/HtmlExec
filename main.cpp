#include "./WebView/webview.h"
#include <iostream>
#include <string>

#ifdef _WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif


using namespace std;
const string APP_NAME = "Test App";

string get_current_dir() {
    char buff[FILENAME_MAX]; //create string buffer to hold path
    GetCurrentDir( buff, FILENAME_MAX );
    string current_working_dir(buff);
    return current_working_dir;
}

#ifdef _WIN32
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

#else
    int main(){
#endif
        webview::webview w(true, nullptr);
        w.set_title(APP_NAME);
        w.set_size(780, 512, WEBVIEW_HINT_NONE);
        string currentPath = "file://";
        currentPath += get_current_dir();
        currentPath += "/source/index.html";
        w.navigate(currentPath);
        w.eval("document.addEventListener('contextmenu', event => event.preventDefault());");
        w.run();
        return 0;
    }
