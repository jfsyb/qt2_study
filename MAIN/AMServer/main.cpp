//#include <QCoreApplication>
#include <stdio.h>
#include <sys/timeb.h>
#include <errno.h>
#include <ctype.h>
#include <string>
#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include<memory.h>
#include<time.h>
//#include <QDateTime>
#if !defined(__linux__)
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <direct.h>
#include <WinSock2.h>
#include <Windows.h>
#define snprintf _snprintf
#else
#include <pthread.h>
#include <stdint.h>
#include <malloc.h>
#include <errno.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/times.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/syscall.h>
#include <linux/serial.h>
#include <dirent.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <netdb.h>
#include <sys/param.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <net/if_arp.h>
#endif
int main(int argc, char *argv[])
{
    int iOldVersion=0;
    bool bNightly=false;
    while(true)
    {
        printf("cat svn change\r\n");
        system("svn info svn://192.168.10.162/AMPRO > temp.dat");
        FILE* fd = fopen("temp.dat","rb");
//        FILE* fd = fopen("1.txt","rb");
        if(NULL!=fd)
        {
            //清空缓存
            char buf[300];
            memset(buf,0,sizeof(buf));
            //读取全部
            fread(buf,sizeof(buf),1,fd);
            fclose(fd);
            //判断是否有程序文件运行
            std::string sTempName=buf;
            int iIndex=sTempName.find("Revision:");
            if(-1!=iIndex)
            {
                int iEndIndex=sTempName.find('\n',iIndex);
                char cTempNum[5];
                memset(cTempNum,0,sizeof(cTempNum));
                memcpy(cTempNum,&buf[iIndex+9],iEndIndex-iIndex-9);
                int iVersion=atoi(cTempNum);
                if(iVersion !=iOldVersion)
                {
                    iOldVersion=iVersion;
                    system("/root/buildGated.sh");                    
                }
            }
            if(!bNightly)
            {
                time_t timep;
                struct tm *p;
                time(&timep);
                p =localtime(&timep);
                if(p->tm_hour ==1)
                {
                    system("/root/buildnightly.sh");
                    system("/root/baksvn.sh");
                    bNightly=true;
                }
            }
            if(bNightly)
            {
                time_t timep;
                struct tm *p;
                time(&timep);
                p =localtime(&timep);
                if(p->tm_hour ==2)
                {
                    bNightly=false;
                }
            }
        }
        sleep(60);
    }
    return 0;
//    QCoreApplication a(argc, argv);

//    return a.exec();
}
