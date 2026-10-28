#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[1024];
    ssize_t bytesRead;

    int src = open("result.txt", O_RDONLY);
    if (src < 0) {
        const char *err = "Error: cannot open result.txt\n";
        write(2, err, 30);
        return 1;
    }

    int dst = open("copyresult.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst < 0) {
        const char *err = "Error: cannot create copyresult.txt\n";
        write(2, err, 36);
        close(src);
        return 1;
    }

    while ((bytesRead = read(src, buffer, sizeof(buffer))) > 0) {
        write(dst, buffer, bytesRead);
    }

    close(src);
    close(dst);

    const char *msg = "File copied successfully!\n";
    write(1, msg, 26);
    return 0;
}
