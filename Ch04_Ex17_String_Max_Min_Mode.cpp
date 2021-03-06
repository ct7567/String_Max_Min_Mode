// Ch04_Ex17_String_Max_Min_Mode.cpp : Defines the entry point for the console application.
//寻找String向量的max，min，和mode

#include "stdafx.h"
#include "e:\temp\[VS2017]\std_lib_facilities.h"

vector <string> string_total;
vector <string> strs;
vector <int> counts;

//检查数值是否与strs向量里已有数值相等
int is_Equal(string s)
{
	for (unsigned int i = 0; i < strs.size(); i++)
	{
		if (s == strs[i])
		{
			return i;	//如果有相等数值的话，返回该数值的位置
			break;
		}
	}
	return -1;	//没有的话返回-1
}


int main()
{
	const int FIRST_ENTRY = 1;	//counts向量的起始值

	string user_str = " ";	//用户输入

	string max_str = "";	//最大的string
	int max_str_i = 0;	//最大的string的位置

	string min_str = "";	//最小的string
	int min_str_i = 0;	//最小的string的位置
		
	int equals = 0;	//检查数值是否与数组里已有数值相等的返回值
	
	int max_count = 0;	//counts向量的最大值
	int max_index = 0;	//counts向量最大值的位置

	cout << ">";

	while (cin >> user_str)
	{
		if (strs.size()==0)	//如果向量是空的
		{
			strs.push_back(user_str);
			counts.push_back(FIRST_ENTRY);
			max_str = user_str;
			min_str = user_str;

			cout << "刚才输入的值是：" << user_str << endl;
		}
		else    //如果向量不是空的
		{
			equals = is_Equal(user_str);

			switch (equals)
			{
			case -1:	//如果没有重复数值的话，vals向量追加，counts向量追加
				strs.push_back(user_str);
				counts.push_back(FIRST_ENTRY);
				break;
			default:	//如果有重复数值的话，对应counts向量追加
				counts[equals]++;
				break;
			}

			//检测用打印
			cout << "Value\t\tCount" << endl;
			for (unsigned int i = 0; i < strs.size(); i++)
			{
				cout << strs[i] << "\t\t" << counts[i] << endl;
			}

			//寻找counts向量最大的值和位置			
			for (unsigned int i = 0; i < strs.size(); i++)
			{
				if (strs[i] > max_str)
				{
					max_str = strs[i];	//最大值
					max_str_i = i;	//最大值的位置
				}
			}

			//寻找counts向量最小的值和位置
			for (unsigned int i = 0; i < strs.size(); i++)	
			{
				if (strs[i] < min_str)
				{
					min_str = strs[i];	//最小值
					min_str_i = i;	//最小值的位置
				}
			}

			//寻找counts向量最大的值和位置
			for (unsigned int i = 0; i < counts.size(); i++)	
			{
				if (counts[i] > max_count)
				{
					max_count = counts[i];	//出现最多的次数
					max_index = i;	//出现最多次数的位置
				}

			}

			cout << "最大值是：" << max_str << "。顺位是：" << max_str_i << "。" << endl;
			cout << "最小值是：" << min_str << "。顺位是：" << min_str_i << "。" << endl;
			cout << "出现频率最高的值是：" << strs[max_index] << "。出现的次数是：" << counts[max_index] << "。" << endl;
		}

		cout << endl << ">";
	}

	keep_window_open();
	return 0;
}

