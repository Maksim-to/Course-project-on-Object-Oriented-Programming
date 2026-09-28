#include "Dll.h"
#include "wtypes.h"
#include "Tech.h"

DataBase DB;

void UpdateFile() {
    DB.WriteFile();
    DB.ReadFile();
};
string ShowAll() {
    return DB.ShowAll();
};

std::string CheckMemory() {
    DB.WriteFile();
    for (int i = 0; i < DB.All.size(); i++) {
        delete DB.All[i];
    }
    DB.All.clear();
    DB.Types.clear();
    HANDLE hCrtLog = CreateFile(TEXT("crt.log"), GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    if (hCrtLog != INVALID_HANDLE_VALUE)
    {
        _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
        _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
        _CrtSetReportFile(_CRT_WARN, hCrtLog);
        _CrtSetReportFile(_CRT_ERROR, hCrtLog);
    }
    _CrtDumpMemoryLeaks();
    if (hCrtLog != INVALID_HANDLE_VALUE)
        CloseHandle(hCrtLog);
    std::ifstream file("crt.log");
    std::string g = "";
    if (file.is_open()) {
        while (!file.eof()) {
            std::string line;
            getline(file, line);
            g += line;
        }
    }
    DB.ReadFile();
    return g;
}

string GetCount() {
    int amount = std::count_if(DB.All.begin(), DB.All.end(), [](Item* a) {
        if (a->GetTextFile() != "") return 1;
        else return 0;
        });
    return std::to_string(amount);
}

bool Reverse() {
    DB.Reverse();
    return true;
}

bool Sort() {
    DB.Sort();
    return 1;
}
bool Swap(int a, int b) {
    a = a - 1;
    b = b - 1;
    if (a >= 0 and b >= 0 and a < DB.All.size() and b < DB.All.size()) {
        iter_swap(DB.All.begin() + a, DB.All.begin() + b);
    }
    return true;
};

void Add(string Title, double price, int amount) {
    DB.Add(Title, price, amount);
}
void Add(string Title, double price, int amount, string producer) {
    DB.Add(Title, price, amount, producer);
}

void Delete(int a) {
    a = a - 1;
    if (a >= 0 and a < DB.All.size()) {
        delete DB.All[a];
    }
    DB.All.erase(DB.All.begin() + a);
};