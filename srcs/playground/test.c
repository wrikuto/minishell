
// #include "../inc/global.h"

#include <unistd.h> // fork(), execve()
#include <stdio.h>

int main() {

    // `man 2 fork` で確認できる、fork() の返り値を格納
    pid_t pid;

    // execve() の引数
    char *argv[3];
    extern char **environ; // プロセスの環境変数

    if((pid = fork()) < 0) { // 失敗時は -1 が返る
        perror("fork failed");
        return 1;
    }
    else if(pid == 0) { // 子プロセスでは pid は 0
        printf("ok from child\n");

        // execve() で実行するプログラムの引数を設定
        argv[0] = "echo"; // 実行プログラム名
        argv[1] = "message from echo program"; // 実行プログラムの引数
        argv[2] = NULL; // 実行プログラムの引数は NULL 終端する必要があります
        execve("/bin/echo", // 実行プログラムへの絶対パス (バイナリまたは実行可能なスクリプトファイル)
               argv,
               environ  // これも NULL 終端されています
               );

        // execve() に成功すると、プロセスID 等は変わらずに実行プログラムに処理が置き換わるため
        // 以下の処理は実行されません。

        _exit(1); // execve() に失敗するとここに到達
    }

    // 親プロセスの場合は、子プロセスの pid > 0
    printf("parent: child process pid = %d\n", pid);
    return 0;
}

