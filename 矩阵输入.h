#include<vector>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;

void output(vector<vector<int>>& matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	cout << "rows:" << rows << ", cols:" << cols << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

//���1��û�и����������������ÿ���е��������Կո����
class type1 {
	//����1������getline�ķ�����stringstream�ָ���������ת�������֣���Ҫ����stoi����;
//�÷����ĺô����ڣ����Դ������Կո��������֣������ö��ż��
	void input1() {
		vector<vector<int>> matrix;
		string line;
		while (getline(cin, line)) {		//��һ������Ϊ�ַ�������
			if (line.size() == 0) break;
			stringstream ss(line);
			string num;						//�˴�������string����
			vector<int> tmp;
			while (getline(ss, num, ' ')) {
				tmp.push_back(stoi(num));	//��Ҫ��stringת��int
			}
			matrix.push_back(tmp);
		}
		output(matrix);
	}

	void input2() {
		vector<vector<int>> matrix;
		string line;
		while (getline(cin, line)) {		//��һ������Ϊ�ַ�������
			if (line.size() == 0) break;
			stringstream ss(line);
			int num;						//��stringstream�����ֱ�Ӵ���int����
			vector<int> tmp;
			while (ss >> num) {				//
				tmp.push_back(num);
			}
			matrix.push_back(tmp);
		}
		output(matrix);
	}
};


//���2��û�и������������������룬���һ����������źͶ��ŵ����룬����Ҳ��ֻ�ܰ����ַ�����������С�
class type2 {
public:

	void input1() {
		vector<vector<int>> matrix;
		string line;
		char* tok;
		while (getline(cin, line)) {		//��һ������Ϊ�ַ�������
			if (line.size() == 0) break;
			tok = strtok((char*)line.c_str(), " ,[]");		//��strtok���зָchar* strtok (char* str,constchar* delimiters );
			vector<int> tmp;
			while (tok != NULL) {
				tmp.push_back(stoi(tok));	
				tok = strtok(NULL, " ,[]");
			}
			matrix.push_back(tmp);
		}
		output(matrix);
	}
};

