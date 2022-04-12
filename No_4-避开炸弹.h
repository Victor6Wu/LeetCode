//给定房间编号1-n，给定m次会出现爆炸的房间编号，问：最少的移动次数
#include<vector>
#include<iostream>
using namespace std;

//贪心法，每次都选择最远一次爆炸的房间，所谓最远的爆炸房间，就是从当前位置往后记录，当1-n的房间都出现后，就需要移动一次，往复操作，一次遍历
//其实不需要记录最远的那个房间具体编号是多少，只需要知道再次1-n的房间都出现后，又需要移动一次即可
//那么，可以用vector记录房间是否出现过，同时用count记录已经出现的房间总数
void result () {
    int n, m;
    cin >> n >> m;
    vector<int> booms(m);   //记录爆炸出现的房间编号
    int room;
    for (int i = 0; i < m; i++) {
        cin >> room;
        booms[i] = room;
    }

    //因为最开始是在房间1，所以找到booms中1第一次出现的地方开始记录
    int index = 0;
    while (index < m && booms[index] != 1) {
        index++;
    }

    int ans = 0;    //记录移动次数
    if (index < m) ans = 1; //如果房间1都没出现过，说明待在1房间始终安全，移动次数为0

    int count = 0;                      //记录已经出现过的房间个数，因为最初的1是被考虑的，所以记录下来
    vector<bool> rooms(n + 1, false);   //遍历过程中记录房间是否出现过
    while (index < m) {
        if (!rooms[booms[index]]) {            //如果当前房间从未出现过
            rooms[booms[index]] = true;
            count++;
        }
        //判断一下此时房间是否都出现了
        if (count == n) {   //如果count == n了，说明1-n号房间都出现过至少一次，则铁定要移动一次（其实应该移动到最后使count == n的那个房间号，因为这个房间就是离当前爆炸最远的房间）
            count = 0;      //重置count
            rooms = vector<bool>(n + 1, false);  //重置rooms
            ans++;
            continue;
        }
        //如果count == n了，那么下次记录的开始要从当前index开始，所以就不用++
        index++;
    }
    cout << ans << endl;
}