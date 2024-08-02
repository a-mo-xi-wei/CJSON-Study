#include<stdio.h>
#include"cJSON.h"

void func()
{
	const char* json_data = { "{\" name\" : \"coolmoying\" ,\"age\" : 22,\"weight\" : 55.5,\"address\" : {\"country\" : \"China\",\"zip-code\" : 111111},\"ski1l\" :[\"C\",\"Java\",\"Python\"],\"student\" : false}" };
	cJSON* root = cJSON_Parse(json_data);
	if (root == NULL)
	{
		printf("%s\n", cJSON_GetErrorPtr());
		return;
	}
	else
	{
		cJSON* address = cJSON_GetObjectItem(root, "address");
		cJSON* country = cJSON_GetObjectItem(address, "country");
		if (cJSON_IsString(country))printf("%s : %s\n", country->string, country->valuestring);
		cJSON* age = cJSON_GetObjectItem(root, "age");
		if (cJSON_IsNumber(age))printf("%s : %d\n", age->string, age->valueint);
	}
	cJSON_Delete(root);
} 

void read_json(cJSON* root)
{
	if (root == NULL)return;
	else
	{
		switch (root->type)
		{
		case cJSON_Object:
		{
			cJSON* child = root->child;
			while (child != NULL)
			{
				read_json(child);
				child = child->next;
			}
		}
			break;
		case cJSON_Array:
		{
			printf("%s\n", root->string);
			int array_size = cJSON_GetArraySize(root);
			for (int i = 0; i < array_size; i++)
			{
				cJSON* item = cJSON_GetArrayItem(root, i);
				read_json(item);
			}
		}
			break;
		case cJSON_String:
			printf("%s : %s\n", root->string, root->valuestring);
			break;
		case cJSON_Number:
			if (root->valuedouble - root->valueint != 0)
				printf("%s : %lf\n", root->string, root->valuedouble);
			else printf("%s : %d\n", root->string, root->valueint);
			break;
		case cJSON_False:
			printf("%s : false\n",root->string);
			break;
		case cJSON_True:
			printf("%s : true\n",root->string);
			break;
		case cJSON_NULL:
			printf("%s : NULL\n",root->string);
			break;
		default:
			break;
		}
	}
}

void test_read_json()
{
	//递归方式解析全部数据
	const char* json_data = { "{\"name\" : \"coolmoying\" ,\"age\" : 22,\"weight\" : 55.5,\"address\" : {\"country\" : \"China\",\"zip-code\" : 111111},\"ski1l\" :[\"C\",\"Java\",\"Python\"],\"student\" : false}" };
	cJSON* root = cJSON_Parse(json_data);
	if (root == NULL)
	{
		printf("%s\n", cJSON_GetErrorPtr());
		return;
	}
	else read_json(root);
}
int main()
{
	//func();
	test_read_json();
	return 0;
}