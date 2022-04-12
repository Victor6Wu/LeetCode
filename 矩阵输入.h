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

//情况1：没有给出矩阵的行列数，每行中的数字是以空格隔开
class type1 {
	//方法1：采用getline的方法将stringstream分割，但是如果想转换成数字，需要调用stoi函数;
//该方法的好处在于，可以处理不是以空格间隔的数字，比如用逗号间隔
	void input1() {
		vector<vector<int>> matrix;
		string line;
		while (getline(cin, line)) {		//将一整行作为字符串读入
			if (line.size() == 0) break;
			stringstream ss(line);
			string num;						//此处必须是string类型
			vector<int> tmp;
			while (getline(ss, num, ' ')) {
				tmp.push_back(stoi(num));	//需要将string转成int
			}
			matrix.push_back(tmp);
		}
		output(matrix);
	}

	void input2() {
		vector<vector<int>> matrix;
		string line;
		while (getline(cin, line)) {		//将一整行作为字符串读入
			if (line.size() == 0) break;
			stringstream ss(line);
			int num;						//将stringstream的输出直接传到int类型
			vector<int> tmp;
			while (ss >> num) {				//
				tmp.push_back(num);
			}
			matrix.push_back(tmp);
		}
		output(matrix);
	}
};


//情况2：没有给定矩阵行列数的输入，而且还包含中括号和逗号的输入，我们也是只能按照字符串拆分来进行。
class type2 {
public:

	void input1() {
		vector<vector<int>> matrix;
		string line;
		char* tok;
		while (getline(cin, line)) {		//将一整行作为字符串读入
			if (line.size() == 0) break;
			tok = strtok((char*)line.c_str(), " ,[]");		//用strtok进行分割，char* strtok (char* str,constchar* delimiters );
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

