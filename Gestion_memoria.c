#ifndef GESTION_MEMORIA_H
#define GESTION_MEMORIA_H

#include <windows.h>
#include <stdio.h>
#include <string.h>

#define SIZE 4096

int main() {
    HANDLE hMapFile;
    char *shared_memory;

    hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, SIZE, NULL);
    if (hMapFile == NULL) {
        printf("Could not create file mapping object (%d).\n", GetLastError());
        return 1;
    }

    shared_memory = (char *)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, SIZE);
    if (shared_memory == NULL) {
        printf("Could not map view of file (%d).\n", GetLastError());
        CloseHandle(hMapFile);
        return 1;
    }

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    char command[] = "child_process.exe"; // Example command, replace with actual child executable if different

    if (!CreateProcess(NULL, command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        printf("CreateProcess failed (%d).\n", GetLastError());
        UnmapViewOfFile(shared_memory);
        CloseHandle(hMapFile);
        return 1;
    }

    strcpy(shared_memory, "Hello, child process!");

    WaitForSingleObject(pi.hProcess, INFINITE);

    UnmapViewOfFile(shared_memory);
    CloseHandle(hMapFile);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}

#endif // GESTION_MEMORIA_H
