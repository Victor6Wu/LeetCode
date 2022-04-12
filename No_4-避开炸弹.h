//����������1-n������m�λ���ֱ�ը�ķ����ţ��ʣ����ٵ��ƶ�����
#include<vector>
#include<iostream>
using namespace std;

//̰�ķ���ÿ�ζ�ѡ����Զһ�α�ը�ķ��䣬��ν��Զ�ı�ը���䣬���Ǵӵ�ǰλ�������¼����1-n�ķ��䶼���ֺ󣬾���Ҫ�ƶ�һ�Σ�����������һ�α���
//��ʵ����Ҫ��¼��Զ���Ǹ�����������Ƕ��٣�ֻ��Ҫ֪���ٴ�1-n�ķ��䶼���ֺ�����Ҫ�ƶ�һ�μ���
//��ô��������vector��¼�����Ƿ���ֹ���ͬʱ��count��¼�Ѿ����ֵķ�������
void result () {
    int n, m;
    cin >> n >> m;
    vector<int> booms(m);   //��¼��ը���ֵķ�����
    int room;
    for (int i = 0; i < m; i++) {
        cin >> room;
        booms[i] = room;
    }

    //��Ϊ�ʼ���ڷ���1�������ҵ�booms��1��һ�γ��ֵĵط���ʼ��¼
    int index = 0;
    while (index < m && booms[index] != 1) {
        index++;
    }

    int ans = 0;    //��¼�ƶ�����
    if (index < m) ans = 1; //�������1��û���ֹ���˵������1����ʼ�հ�ȫ���ƶ�����Ϊ0

    int count = 0;                      //��¼�Ѿ����ֹ��ķ����������Ϊ�����1�Ǳ����ǵģ����Լ�¼����
    vector<bool> rooms(n + 1, false);   //���������м�¼�����Ƿ���ֹ�
    while (index < m) {
        if (!rooms[booms[index]]) {            //�����ǰ�����δ���ֹ�
            rooms[booms[index]] = true;
            count++;
        }
        //�ж�һ�´�ʱ�����Ƿ񶼳�����
        if (count == n) {   //���count == n�ˣ�˵��1-n�ŷ��䶼���ֹ�����һ�Σ�������Ҫ�ƶ�һ�Σ���ʵӦ���ƶ������ʹcount == n���Ǹ�����ţ���Ϊ�����������뵱ǰ��ը��Զ�ķ��䣩
            count = 0;      //����count
            rooms = vector<bool>(n + 1, false);  //����rooms
            ans++;
            continue;
        }
        //���count == n�ˣ���ô�´μ�¼�Ŀ�ʼҪ�ӵ�ǰindex��ʼ�����ԾͲ���++
        index++;
    }
    cout << ans << endl;
}