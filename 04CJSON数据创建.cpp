#include"cJSON.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void create_json_data()
{
	cJSON* root = cJSON_CreateObject();
	//添加内容
	//基本内容
	cJSON_AddStringToObject(root, "name", "威爷");
	cJSON_AddNumberToObject(root, "age", 20);
	cJSON* address = cJSON_CreateObject();
	cJSON_AddStringToObject(address, "city", "北京");
	cJSON_AddStringToObject(address, "area", "朝阳");
	cJSON_AddItemToObject(root, "address", address);
	cJSON* score = cJSON_CreateArray();
	for (int i = 0; i < 5; i++)
	{
		cJSON_AddItemToArray(score,cJSON_CreateNumber(rand()%10+90));
	}
	cJSON_AddItemToObject(root, "score",score);
	puts(cJSON_Print(root));
}


int main()
{
	srand((unsigned int)time(NULL));
	create_json_data();
	perror("错误");
}