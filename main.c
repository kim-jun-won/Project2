#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;
struct tm time1_val, time2_val;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main()
{
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

void filetime1(){
    localtime_r(&stat1.st_mtime, &time1_val);
    time1 = &time1_val;
}

// 파일 1의 시간 정보를 가져오는 함수 작성
void filetime2()
{
    localtime_r(&stat2.st_mtime, &time2_val);
    time2 = &time2_val;
}

// 두 개의 파일 크기를 비교하는 함수 작성
void sizecmp()
{
    printf("size compare\n");
    if (stat1.st_size > stat2.st_size)
        printf("text1 is bigger\n\n");
    else if (stat1.st_size < stat2.st_size)
        printf("text2 is bigger\n\n");
    else
        printf("sizes are equal\n\n");
}

// 두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp()
{
    printf("block compare\n");
    if (stat1.st_blocks > stat2.st_blocks)
        printf("text1 is bigger\n\n");
    else if (stat1.st_blocks < stat2.st_blocks)
        printf("text2 is bigger\n\n");
    else
        printf("sizes are equal\n\n");
}

void datecmp() {
    printf("date compare\n");

    if (time1 == NULL || time2 == NULL) {
        printf("Error: One of the time values is NULL.\n");
        return;
    }

    if (time1->tm_year < time2->tm_year)
        printf("text1 is early\n");
    else if (time1->tm_year > time2->tm_year)
        printf("text2 is early\n");
    else if (time1->tm_mon < time2->tm_mon)
        printf("text1 is early\n");
    else if (time1->tm_mon > time2->tm_mon)
        printf("text2 is early\n");
    else if (time1->tm_mday < time2->tm_mday)
        printf("text1 is early\n");
    else if (time1->tm_mday > time2->tm_mday)
        printf("text2 is early\n");
    else
        printf("same date\n");
}

void timecmp() {
    printf("\ntime compare\n");

    if (time1 == NULL || time2 == NULL) {
        printf("Error: One of the time values is NULL.\n");
        return;
    }

    if (time1->tm_hour < time2->tm_hour)
        printf("text1 is early\n");
    else if (time1->tm_hour > time2->tm_hour)
        printf("text2 is early\n");
    else if (time1->tm_min < time2->tm_min)
        printf("text1 is early\n");
    else if (time1->tm_min > time2->tm_min)
        printf("text2 is early\n");
    else if (time1->tm_sec < time2->tm_sec)
        printf("text1 is early\n");
    else if (time1->tm_sec > time2->tm_sec)
        printf("text2 is early\n");
    else
        printf("same time\n");
}
