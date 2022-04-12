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
	DoubleList* head, * tail;
	unordered_map<int, DoubleList*> memory;
public:
	LRU(int _capacity) {
		this->capacity = _capacity;
		head = new DoubleList(-1, -1);
		tail = new DoubleList(-1, -1);
		head->next = tail;
		tail->pre = head;
	}
	~LRU() {
		if (head != nullptr) {
			delete head;
			head = nullptr;
		}
		if (tail != nullptr) {
			delete tail;
			tail = nullptr;
		}
		for (auto& a : memory) {
			if (a.second != nullptr) {
				delete a.second;
				a.second = nullptr;
			}
		}
	}
	void set(int _key, int _val) {
		if (memory.find(_key) != memory.end()) {
			DoubleList* node = memory[_key];
			removeNode(node);
			node->val = _val;
			pushNode(node);
			return;
		}
		if (memory.size() == this->capacity) {// �������Ҫ��Ҳ�ܰ���ǧ��ǵø���memory
			int topKey = head->next->key;//ȡ��keyֵ�������ں���ɾ��
			removeNode(head->next);//�Ƴ�ͷ������һ��
			memory.erase(topKey);//��memory��ɾ����ǰͷ����ֵ
		}
		DoubleList* node = new DoubleList(_key, _val);//����node
		pushNode(node);//����β��
		memory[_key] = node;//�ǵ���memory����ӽ�ȥ
	}
	int get(int _key) {
		if (memory.find(_key) != memory.end()) {
			DoubleList* node = memory[_key];
			removeNode(node);
			pushNode(node);
			return node->val;
		}
		return -1;
	}
	void removeNode(DoubleList* node) {
		node->pre->next = node->next;
		node->next->pre = node->pre;
	}
	void pushNode(DoubleList* node) {
		tail->pre->next = node;
		node->pre = tail->pre;
		node->next = tail;
		tail->pre = node;
	}
};