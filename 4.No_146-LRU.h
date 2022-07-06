//���˸о�LRU�Ĵ����TinyWebSever��Ŀ�ж�ʱ���Ķ������ƣ�ά��һ��˫��������һ����ϣ����Ϊ����
#include<unordered_map>
using namespace std;

//���Ľڵ�
struct DoubleList {
	int key, val;
	DoubleList* pre, * next;
	DoubleList(int _key, int _val) :key(_key), val(_val), pre(nullptr), next(nullptr) { }
};


class LRU {
private:
	int capacity;
	DoubleList* head, * tail;		//�����ͷβ�ڵ�
	unordered_map<int, DoubleList*> memory;		//��ϣ��
public:
	LRU(int _capacity) {
		this->capacity = _capacity;
		head = new DoubleList(-1, -1);
		tail = new DoubleList(-1, -1);
		head->next = tail;
		tail->pre = head;
	}
	~LRU() {
		//�ͷ�ͷ�ڵ��ڴ�
		if (head != nullptr) {
			delete head;
			head = nullptr;
		}
		//�ͷ�β�ڵ��ڴ�
		if (tail != nullptr) {
			delete tail;
			tail = nullptr;
		}
		//ѭ���ͷ�memory�е�ÿ��key��Ӧ���ڴ�
		for (auto& a : memory) {
			if (a.second != nullptr) {
				delete a.second;			//�ͷŶ���������ڴ�
				a.second = nullptr;
			}
		}
	}

	//�����µ�key-value
	void put(int _key, int _val) {
		//����Ѿ����ڣ���ı���value�����������е�λ�ü���
		if (memory.find(_key) != memory.end()) {
			DoubleList* node = memory[_key];
			removeNode(node);
			node->val = _val;
			pushNode(node);
			return;
		}
		//memory�в����ڣ�˵�����²���Ľڵ㣬Ҫ�ж�һ���Ƿ�����
		if (memory.size() == this->capacity) {// �������Ҫ��Ҳ�ܰ���ǧ��ǵø���memory
			int topKey = head->next->key;//ȡ��keyֵ�������ں���ɾ��
			removeNode(head->next);//�Ƴ�ͷ������һ��
			memory.erase(topKey);//��memory��ɾ����ǰͷ����ֵ
		}
		DoubleList* node = new DoubleList(_key, _val);//����node
		pushNode(node);//����β��
		memory[_key] = node;//�ǵ���memory����ӽ�ȥ
	}

	//����keyֵ��ȡvalue��ֱ���ڹ�ϣ��memory�в�ѯ���ɣ��ǵõ����ڵ��������е�λ��
	int get(int _key) {
		if (memory.find(_key) != memory.end()) {
			DoubleList* node = memory[_key];
			removeNode(node);
			pushNode(node);
			return node->val;
		}
		return -1;
	}

	//��Ϊ����Ͳ�ѯ���Ǹ���keyֵ����ʵ�ʵ�ά���Ƿ�װ��Node�еģ�����Ҫ�ṩ�����ڵ�λ�õĽӿ�
	//1.�Ƴ��ڵ�
	void removeNode(DoubleList* node) {
		node->pre->next = node->next;
		node->next->pre = node->pre;
	}
	//2.��β������ڵ�
	void pushNode(DoubleList* node) {
		tail->pre->next = node;
		node->pre = tail->pre;
		node->next = tail;
		tail->pre = node;
	}
};