//void* memcpy(void* str1, const void* str2, size_t n)
//str1 -- ָ�����ڴ洢�������ݵ�Ŀ�����飬����ǿ��ת��Ϊ void* ָ�롣
//str2 -- ָ��Ҫ���Ƶ�����Դ������ǿ��ת��Ϊ void* ָ�롣
//n -- Ҫ�����Ƶ��ֽ�����

//1.ʹ��memcpy()��ʾ����
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

//2.ʵ�ֺ��� 
//�汾һ�����ֽڿ�����������д���ǣ���ַ�ص���
void* mymemcpy1(void* des, const void* src, unsigned int n) {
	assert(des != NULL && src != NULL);
	//����׵�ַ
	char* Pdes = (char*)des;
	char* Psrc = (char*)src;
	
	while (n-- > 0) {
		*Pdes = *Psrc;		//��Psrc��ָ��ĵ�ַ�е����ݿ�����Pdes��ָ��ַ
		Pdes++;				//Pdes�ڵ���ֵ(��ַ)+1����ָ����һ����ַ
		Psrc++;
	}
	return des;
}

//�汾�������ֽڿ���������д�ص���src + len > des
void* mymemcpy2(void* des, const void* src, size_t n) {
	assert(des != NULL && src != NULL);
	char* Pdes = (char*)des;
	char* Psrc = (char*)src;

	//������������ص��벻�ص�
	if (Psrc < Pdes && Psrc + n > des) {
		//����д����ʱ��Ҫ���𿽱�
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

//�汾������4�ֽ�(int)����������д�ص�
void* mymemcpy3(void* des, void* src, size_t n) {
	assert(des != NULL && src != NULL);
	//ת����int*���ͣ��ƶ���λ���4�ֽ�
	int* Pdes = (int*)des;
	int* Psrc = (int*)src;
	char* tmp1 = NULL;
	char* tmp2 = NULL;	
	int count1 = n / 4;	//����4�ֽڿ����Ĵ���
	int count2 = n % 4;	//ʣ�಻��4�ֽڵĴ���

	//ע��˴��ж��Ƿ����д����ʱ��Ҫ��Psrc��Pdesת��char*
	if (Psrc < Pdes && (char*)Psrc + n > (char*)Pdes) {
		tmp1 = (char*)Pdes + n - 1;
		tmp2 = (char*)Psrc + n - 1;
		while (count2-- > 0) {
			*tmp1 = *tmp2;
			tmp1--;
			tmp2--;
		}

		//ע�⣺��ʱtmp�����λ�ã��Ǳ�PdesӦ�õ���ʼλ��Сһ���ֽڵģ�Ҫ�������
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