//void* memcpy(void* str1, const void* str2, size_t n)
//str1 -- 指向用于存储复制内容的目标数组，类型强制转换为 void* 指针。
//str2 -- 指向要复制的数据源，类型强制转换为 void* 指针。
//n -- 要被复制的字节数。

//1.使用memcpy()，示例：
#include<stdio.h>
#include<assert.h>
#include<string.h>

struct myperson {
	char name[40];
	int age;
};

void Test () {
	myperson person, person_copy;
	char myname[] = "Pierre de Fermat";

	//using memcpy to copy string:
	memcpy(person.name, myname, strlen(myname) + 1);
	person.age = 46;

	//using memcpy to copy structure:
	memcpy(&person_copy, &person, sizeof(person));

	printf("person_copy:%s, %d \n", person_copy.name, person_copy.age);
}

//2.实现函数 
//版本一：按字节拷贝，不考虑写覆盖（地址重叠）
void* mymemcpy1(void* des, const void* src, unsigned int n) {
	assert(des != NULL && src != NULL);
	//获得首地址
	char* Pdes = (char*)des;
	char* Psrc = (char*)src;
	
	while (n-- > 0) {
		*Pdes = *Psrc;		//将Psrc所指向的地址中的内容拷贝给Pdes所指地址
		Pdes++;				//Pdes内的数值(地址)+1，即指向下一个地址
		Psrc++;
	}
	return des;
}

//版本二：按字节拷贝，考虑写重叠：src + len > des
void* mymemcpy2(void* des, const void* src, size_t n) {
	assert(des != NULL && src != NULL);
	char* Pdes = (char*)des;
	char* Psrc = (char*)src;

	//分两种情况，重叠与不重叠
	if (Psrc < Pdes && Psrc + n > des) {
		//存在写覆盖时，要倒叙拷贝
		Psrc = Psrc + n - 1;
		Pdes = Pdes + n - 1;
		while (n-- > 0) {
			*Pdes = *Psrc;
			Pdes--;
			Psrc--;
		}
	}
	else {
		while (n-- > 0) {
			*Pdes = *Psrc;
			Pdes++;
			Psrc++;
		}
	}
	return des;
}

//版本三：按4字节(int)拷贝，考虑写重叠
void* mymemcpy3(void* des, void* src, size_t n) {
	assert(des != NULL && src != NULL);
	//转换成int*类型，移动单位变成4字节
	int* Pdes = (int*)des;
	int* Psrc = (int*)src;
	char* tmp1 = NULL;
	char* tmp2 = NULL;	
	int count1 = n / 4;	//满足4字节拷贝的次数
	int count2 = n % 4;	//剩余不足4字节的次数

	//注意此处判断是否存在写覆盖时，要将Psrc和Pdes转成char*
	if (Psrc < Pdes && (char*)Psrc + n > (char*)Pdes) {
		tmp1 = (char*)Pdes + n - 1;
		tmp2 = (char*)Psrc + n - 1;
		while (count2-- > 0) {
			*tmp1 = *tmp2;
			tmp1--;
			tmp2--;
		}

		//注意：此时tmp到达的位置，是比Pdes应该的起始位置小一个字节的，要给予调整
		tmp1++;
		tmp2++;

		Pdes = (int*)tmp1;
		Psrc = (int*)tmp2;
		while (count1-- > 0) {
			*Pdes = *Psrc;
			Pdes--;
			Psrc--;
		}
	}
	else {
		while (count1-- > 0) {
			*Pdes = *Psrc;
			Pdes++;
			Psrc++;
		}
		tmp1 = (char*)Pdes;
		tmp2 = (char*)Psrc;
		while (count2-- > 0) {
			*tmp1 = *tmp2;
			tmp1++;
			tmp2++;
		}
	}
	return des;
}