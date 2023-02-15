#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Sender.h"
#include "testCases_Sender.h"


const FuncPtrTestSenderType sendFunPtr[] =
{
    (FuncPtrTestSenderType) SendToServer,
    (FuncPtrTestSenderType) testSendToServer
};

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        printf("Usage: %s [-t]/[-r]\n[-t]: To run the unit test cases\n[-r]: To send the sensors data via console output\n", argv[0]);
        exit(0);
    }

    if(strcmp(argv[1],"-t") == 0)
    {
        testCases_Sender();
    }
    else if(strcmp(argv[1],"-r") == 0)
    {
        (*(sendFunPtr[0]))();
    }
    return 0;
}