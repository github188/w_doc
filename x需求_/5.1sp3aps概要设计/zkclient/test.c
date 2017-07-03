#include "client.h"


void cli_start_handler(void *handler_arg)
{
    printf("zk close\n");
}


void get_handler(const char *value, int len, void *handler_arg)
{
    printf("aget value is %s\n", value);
}



void watch_handler(const char *value, int len, void *handler_arg)
{
    printf("watch value is %s\n", value);
}


void watch_children_handler(char **data, int32_t count, void *handler_arg)
{
    if(count==0)
    {
        printf("no children%s\n");
    }
    else if(count==-1)
    {
        printf("the node not exist, watch failure%s\n");
    }
    else
    {
        int i=0;
        for(; i<count; i++)
        {
            printf("number %d is %s\n", i, data[i]);
        }
    }

}



int main(int argc, const char *argv[])  
{  
    const char* hosts = "172.16.186.59:2181";  
    int timeout = 30000;  

    Para para1;
    para1.domain_moid = "domain_moid";
    para1.resource_moid = "room_moid";
    para1.server = "pas";
    para1.server_moid = "moid";
    para1.node = "config";


    Para para2;
    para2.domain_moid = "domain_moid";
    para2.resource_moid = "room_moid";
    para2.server = "ap";
    para2.server_moid = "moid";
    para2.node = "control";


    Para para3;
    para3.domain_moid = "domain_moid";
    para3.resource_moid = "room_moid";
    para3.server = "ap";
    para3.server_moid = "moid";
    para3.node = NULL;


    zhandle_t* zkhandle = start(hosts, cli_start_handler, NULL);
    if (zkhandle == NULL)  
    {  
        fprintf(stderr, "Error when connecting to zookeeper servers...\n");  
        exit(EXIT_FAILURE);  
    }


    getchar();


    // char value[1024];
    // int value_len=sizeof(value);
    // memset(value, 0, value_len);
    // int flag=get_data_by_sync(zkhandle, &para1, value, &value_len);
    
    // printf("get flag is %d\n", flag);
    // // printf("%d\n", value_len);
    // printf("get value is %s\n", value);

    // getchar();


    // int flag1=get_data_by_async(zkhandle, get_handler, NULL, &para1);
    // printf("aget flag1 is %d\n", flag1);
    
    // getchar();


    // int flag2=watch_data(zkhandle, watch_handler, NULL, &para2);

    // printf("watch flag2 is %d\n", flag2);
    
    // getchar();



    // printf("set flag3 \n");
    // int flag3=update_data(zkhandle, "run", &para2);

    // printf("set flag3 is %d\n", flag3);
    
    // getchar();


    char *data[10];
    int32_t count;


    int i=0;
    for(;i<10;i++)
    {
        data[i]=(char *)malloc(sizeof(char)*100);
        memset(data[i], 0, sizeof(data[i]));
    }
        

    int flag4=get_children(zkhandle, &para3, data, &count);


    for(i=0; i<count; i++)
    {
        printf("number %d is %s\n", i, data[i]);
    }


    printf("get children flag4 is %d\n", flag4);
    

    for(i=0;i<10;i++)
    {
        free(data[i]);
    }
    getchar();


    int flag5=watch_children_name(zkhandle,  watch_children_handler, NULL, &para3);

    printf("watch children flag5 is %d\n", flag5);
    
    getchar();
}  