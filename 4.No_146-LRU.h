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
	DoubleList* head, * tail;		//链表的头尾节点
	unordered_map<int, DoubleList*> memory;		//哈希表
public:
	LRU(int _capacity) {
		this->capacity = _capacity;
		head = new DoubleList(-1, -1);
		tail = new DoubleList(-1, -1);
		head->next = tail;
		tail->pre = head;
	}
	~LRU() {
		//释放头节点内存
		if (head != nullptr) {
			delete head;
			head = nullptr;
		}
		//释放尾节点内存
		if (tail != nullptr) {
			delete tail;
			tail = nullptr;
		}
		//循环释放memory中的每个key对应的内存
		for (auto& a : memory) {
			if (a.second != nullptr) {
				delete a.second;			//释放堆区分配的内存
				a.second = nullptr;
			}
		}
	}

	//插入新的key-value
	void put(int _key, int _val) {
		//如果已经存在，则改变其value，调整链表中的位置即可
		if (memory.find(_key) != memory.end()) {
			DoubleList* node = memory[_key];
			removeNode(node);
			node->val = _val;
			pushNode(node);
			return;
		}
		//memory中不存在，说明是新插入的节点，要判断一下是否会溢出
		if (memory.size() == this->capacity) {// 这里很重要，也很爱错，千万记得更新memory
			int topKey = head->next->key;//取得key值，方便在后面删除
			removeNode(head->next);//移除头部的下一个
			memory.erase(topKey);//在memory中删除当前头部的值
		}
		DoubleList* node = new DoubleList(_key, _val);//新增node
		pushNode(node);//放在尾部
		memory[_key] = node;//记得在memory中添加进去
	}

	//根据key值获取value，直接在哈希表memory中查询即可，记得调整节点在链表中的位置
	int get(int _key) {
		if (memory.find(_key) != memory.end()) {
			DoubleList* node = memory[_key];
			removeNode(node);
			pushNode(node);
			return node->val;
		}
		return -1;
	}

	//因为插入和查询都是根据key值，而实际的维护是封装在Node中的，所以要提供调整节点位置的接口
	//1.移除节点
	void removeNode(DoubleList* node) {
		node->pre->next = node->next;
		node->next->pre = node->pre;
	}
	//2.在尾部插入节点
	void pushNode(DoubleList* node) {
		tail->pre->next = node;
		node->pre = tail->pre;
		node->next = tail;
		tail->pre = node;
	}
};