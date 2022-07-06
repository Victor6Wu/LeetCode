#include<unordered_map>
#include<list>
using namespace std;

struct Node {
	int key, val, freq;
	Node(int _key, int _val, int _freq) :key(_key), val(_val), freq(_freq) {}
};


//д��1���������Node*
class LFUCache {
	int minfreq, capacity;
	unordered_map<int, list<Node*>::iterator> key_table;		//�˴�key_table�е�value�������list<Node*>::iterator���ͣ���Ϊ�õ�stl�е�list.erase
	unordered_map<int, list<Node*>> freq_table;					//freq_table�е�ÿ��list�������Ľڵ�ᱻ��������ͷ��
public:
	LFUCache(int _capacity) :minfreq(0), capacity(_capacity) {
		this->key_table.clear();
		this->freq_table.clear();
	}

	int get(int key) {
		if (key_table.find(key) != key_table.end()) {
			list<Node*>::iterator it_node = key_table[key];		//ע��˴�it_node�ǵ�����������Node*
			Node* node = *it_node;								//node����
			int tmp_freq = node->freq;
			node->freq++;
			//����freq_table
			freq_table[tmp_freq].erase(it_node);
			freq_table[tmp_freq + 1].emplace_front(node);		//��ǰ����
			//����minfreq
			if (freq_table[tmp_freq].size() == 0) {
				freq_table.erase(tmp_freq);
				if (minfreq == tmp_freq) minfreq++;
			}
			//����key_table������ոմ洢�ĵ�����
			key_table[key] = freq_table[tmp_freq + 1].begin();	//��ʱ��begin���Ǹող���Ľڵ㣬Ҳ��ΪʲôҪ���½ڵ����ͷ����ԭ��
			return node->val;
		}
		return -1;
	}

	void put(int key, int value) {
		//�ǳ���Ҫ��һ�䣬����ᵼ�� int minKey = freq_table[minfreq].back()->key; ����
		if (capacity == 0) return;

		if (key_table.find(key) != key_table.end()) {
			list<Node*>::iterator it_node = key_table[key];
			Node* node = *it_node;
			int tmp_freq = node->freq;
			node->freq++;
			node->val = value;
			freq_table[tmp_freq].erase(it_node);
			freq_table[tmp_freq + 1].emplace_front(node);
			if (freq_table[tmp_freq].size() == 0) {
				freq_table.erase(tmp_freq);
				if (minfreq == tmp_freq) minfreq++;
			}
			key_table[key] = freq_table[tmp_freq + 1].begin();
		}
		//��Ҫ�����µĽڵ�
		else {	
			//��ǰ��������Ҫɾ��freq��С�����Ľڵ�
			if (key_table.size() == capacity) {
				int minKey = freq_table[minfreq].back()->key;
				key_table.erase(minKey);
				freq_table[minfreq].pop_back();
				if (freq_table[minfreq].size() == 0) freq_table.erase(minfreq);
			}
			//�����½ڵ㣬freqһ����1
			Node* node = new Node(key, value, 1);
			freq_table[1].emplace_front(node);
			key_table[key] = freq_table[1].begin();
			minfreq = 1;
		}
	}
};


//д��2���������Node
class LFUCache {
	int minfreq, capacity;
	unordered_map<int, list<Node>::iterator> key_table;
	unordered_map<int, list<Node>> freq_table;
public:
	LFUCache(int _capacity) {
		minfreq = 0;
		capacity = _capacity;
		key_table.clear();
		freq_table.clear();
	}

	int get(int key) {
		if (capacity == 0) return -1;
		auto it = key_table.find(key);
		if (it == key_table.end()) return -1;
		list<Node>::iterator node = it->second;
		int val = node->val, freq = node->freq;
		freq_table[freq].erase(node);
		// �����ǰ����Ϊ�գ�������Ҫ�ڹ�ϣ����ɾ�����Ҹ���minFreq
		if (freq_table[freq].size() == 0) {
			freq_table.erase(freq);
			if (minfreq == freq) minfreq += 1;
		}
		// ���뵽 freq + 1 ��
		freq_table[freq + 1].push_front(Node(key, val, freq + 1));
		key_table[key] = freq_table[freq + 1].begin();
		return val;
	}

	void put(int key, int value) {
		if (capacity == 0) return;
		auto it = key_table.find(key);
		if (it == key_table.end()) {
			// ������������Ҫ����ɾ������
			if (key_table.size() == capacity) {
				// ͨ�� minFreq �õ� freq_table[minFreq] �����ĩβ�ڵ�
				auto it2 = freq_table[minfreq].back();
				key_table.erase(it2.key);
				freq_table[minfreq].pop_back();
				if (freq_table[minfreq].size() == 0) {
					freq_table.erase(minfreq);
				}
			}
			freq_table[1].push_front(Node(key, value, 1));
			key_table[key] = freq_table[1].begin();
			minfreq = 1;
		}
		else {
			// �� get ��������һ�£�������Ҫ���»����ֵ
			list<Node>::iterator node = it->second;
			int freq = node->freq;
			freq_table[freq].erase(node);
			if (freq_table[freq].size() == 0) {
				freq_table.erase(freq);
				if (minfreq == freq) minfreq += 1;
			}
			freq_table[freq + 1].push_front(Node(key, value, freq + 1));
			key_table[key] = freq_table[freq + 1].begin();
		}
	}
};