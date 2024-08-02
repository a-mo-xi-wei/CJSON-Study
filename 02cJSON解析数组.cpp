#include"cJSON.h"
#include<stdlib.h>
#include<stdio.h>
void func1()
{
	//一维数组解析

	const char* json_data = { "[1,2,3,4,5,6]" };
	cJSON* root = cJSON_Parse(json_data);
	if (root == NULL)
	{
		printf("%s\n", cJSON_GetErrorPtr());
		return;
	}
	else
	{
		int array_size = cJSON_GetArraySize(root);
		printf("size = %d\n", array_size);
		for (int i = 0; i < array_size; i++)
		{
			cJSON* item = cJSON_GetArrayItem(root, i);
			if (cJSON_IsNumber(item))printf("%d ", item->valueint);
		}
	}
	printf("\n");
	cJSON_Delete(root);
}

void func2()
{
	//二维数组解析

	const char* json_data = { "{\"array\":[[1,2,3,4],[3,4,5,6],[1,32,3,66,44,3,3,3]]}" };
	cJSON* root = cJSON_Parse(json_data);
	cJSON* array = cJSON_GetObjectItem(root, "array");
	int rows = cJSON_GetArraySize(array);
	for (int i = 0; i < rows; i++)
	{
		cJSON* row_json = cJSON_GetArrayItem(array, i);
		int size = cJSON_GetArraySize(row_json);
		printf("%d\n", size);
		for (int j = 0; j < size; j++)
		{
			cJSON* item = cJSON_GetArrayItem(row_json, j);
			if (cJSON_IsNumber(item))printf("%d ", item->valueint);
		}
		printf("\n");
	}
	cJSON_Delete(root);
}


int main()
{
	func2();
	return 0;
}