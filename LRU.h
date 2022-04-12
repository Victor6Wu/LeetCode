//个人感觉LRU的代码和TinyWebSever项目中定时器的定义类似，维护一个双向链表，和一个哈希表作为缓存
#include<unordered_map>
using namespace std;

//链的节点
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
		if (memory.size() == this->capacity) {// 这里很重要，也很爱错，千万记得更新memory
			int topKey = head->next->key;//取得key值，方便在后面删除
			removeNode(head->next);//移除头部的下一个
			memory.erase(topKey);//在memory中删除当前头部的值
		}
		DoubleList* node = new DoubleList(_key, _val);//新增node
		pushNode(node);//放在尾部
		memory[_key] = node;//记得在memory中添加进去
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