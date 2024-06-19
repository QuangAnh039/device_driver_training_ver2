#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

void printFileInfo(char *folderPath, char *fileName) {
    char filePath[1024];
    snprintf(filePath, sizeof(filePath), "%s/%s", folderPath, fileName);

    struct stat fileStat;
    if (stat(filePath, &fileStat) == -1) {
        perror("Error getting file information");
        return;
    }

    // Print file name
    printf("Name: %s\n", fileName);

    // Print file size
    printf("Size: %ld bytes\n", fileStat.st_size);

    // Print modification time
    char modTime[20];
    struct tm *tm_info = localtime(&fileStat.st_mtime);
    strftime(modTime, sizeof(modTime), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Modify Time: %s\n", modTime);

    printf("\n");
}

int main(int argc , char * argv[]) {
    if (argc < 2) 
    {
        perror("syntax error\n");
        return EXIT_FAILURE;
    }
    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("Error opening directory");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip . and ..
        if (entry->d_name[0] == '.' && (entry->d_name[1] == '\0' || (entry->d_name[1] == '.' && entry->d_name[2] == '\0'))) 
        {
            continue;
        }

        printFileInfo(argv[1], entry->d_name);
    }

    closedir(dir);
    return EXIT_SUCCESS;
}