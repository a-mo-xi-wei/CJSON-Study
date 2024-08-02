#include"cJSON.h"
#include<stdio.h>
int main()
{
	//唯一注意点 ：转义字符问题
	const char* json_data = { "{\"name\":\"coolmoying\",\"age\":12}" };
	cJSON* json = cJSON_Parse(json_data);
	if (!json)
	{
		puts("json 构建失败！\n");
		printf("%s\n", cJSON_GetErrorPtr());
		return 0;
	}
	else
	{
		cJSON* json_name = cJSON_GetObjectItem(json, "name");
		if (json_name->type == cJSON_String)
			printf("%s : %s\n", json_name->string, json_name->valuestring);
			//puts(json_name->valuestring);
		cJSON* json_age = cJSON_GetObjectItem(json, "age");
		if (json_age->type == cJSON_Number)
			printf("%s : %d\n", json_age->string,json_age->valueint);
		//第二种方案
		if (cJSON_IsString(json_name))
			printf("%s : %s\n", json_name->string, json_name->valuestring);
			//puts(json_name->valuestring);
		if (cJSON_IsNumber(json_age))
			printf("%s : %d\n", json_age->string, json_age->valueint);

	}
	puts(cJSON_Print(json));
	cJSON_Delete(json);
}