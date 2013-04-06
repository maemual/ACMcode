#include <iostream>  
#include <cstring>  
#include <limits>  
#include <vector>  
#include <queue>  
#include <stack>  
#include <set>  
#include <map>  
      
using namespace std;  
      
#define SQUARES 4       // 局面横向格子数。  
#define BASE 16         // 将局面转换为整数的基数。  
#define DEPTHBOUND 30       // 使用深度优先搜索时的最大搜索深度。  
#define STEPSBOUND 50       // 解的最大长度。  
      
#define MOVE_LEFT (-1)  
#define MOVE_RIGHT 1  
#define MOVE_UP (-SQUARES)  
#define MOVE_DOWN SQUARES  
#define MOVE_NONE 0  
      
int manhattan[SQUARES * SQUARES][SQUARES * SQUARES];    // 预先计算的曼哈顿距离表。  
int move[SQUARES];  // 后续移动。  
      
// 当前棋面状态相关数据的一个结构。  
struct node  
{  
    vector < int > state;     // 表示当前棋盘状态。  
    int moves[STEPSBOUND];      // 从初始状态到达该状态的走法序列。  
    int depth;          // 当前深度。  
    int score;          // 当前节点的评分。  
    int blank;          // 空格位置。  
};  
      
// 优先队列的比较函数。分值较小的在优先队列的前端。  
bool operator<(node x, node y)  
{  
    return x.score > y.score;  
}  
      
// 求绝对值。  
int absi(int x)  
{  
    return x >= 0 ? x : (-x);  
}  
      
// 判断给定局面是否可解。  
bool solvable(vector < int > tiles)  
{  
    int sum = 0, row;  
    for (int i = 0; i < tiles.size(); i++)  
    {  
        int tile = tiles[i];  
        if (tile == 0)  
        {  
            row = (i / SQUARES + 1);  
            continue;  
        }  
  
        for (int m = i; m < tiles.size(); m++)  
            if (tiles[m] < tile && tiles[m] != 0)  
                sum++;  
    }  
      
    return !((sum + row) % 2);  
}  
      
// 得到当前局面的后继走法。MOVE_LEFT = 向左移动空滑块，MOVE_RIGHT = 向右移动空滑块，  
// MOVE_UP = 向上移动空滑块，MOVE_DOWN = 向下移动空滑块。  
void valid_moves(node &current)  
{  
    // 获取后继走法，但除去退回到该状态的上一步的走法。  
    int last_move = MOVE_NONE;  
    if (current.depth)  
        last_move = current.moves[current.depth - 1];  
      
    memset(move, MOVE_NONE, sizeof(move));  
    if (current.blank % SQUARES > 0 && last_move != MOVE_RIGHT)  
        move[0] = MOVE_LEFT;;  
    if (current.blank % SQUARES < (SQUARES - 1) && last_move != MOVE_LEFT)  
        move[1] = MOVE_RIGHT;  
    if (current.blank / SQUARES > 0 && last_move != MOVE_DOWN)  
        move[2] = MOVE_UP;  
    if (current.blank / SQUARES < (SQUARES - 1) && last_move != MOVE_UP)  
        move[3] = MOVE_DOWN;  
}  
      
// 将棋面状态转换为一个整数。  
unsigned long long key(vector < int > &tiles)  
{  
    unsigned long long key = 0;  
    for (int i = 0; i < tiles.size(); i++)  
        key = key * BASE + tiles[i];  
    return key;  
}  
      
// 从局面 current 执行 move 所指定的走法。  
node execute(node &current, int move)  
{  
    node successor;  
      
    // 走法步骤设定。  
    memcpy(successor.moves, current.moves, sizeof(current.moves));  
    successor.depth = current.depth + 1;  
    successor.moves[current.depth] = move;  
      
    // 局面状态设定。按 move 指定方向移动，交换空滑块位置。  
    successor.state = current.state;  
    successor.blank = current.blank + move;  
    successor.state[current.blank] = successor.state[successor.blank];  
    successor.state[successor.blank] = 0;  
      
    return successor;  
}  
  
// 由于 h*（n） 在算法中非常关键，而且它是高度特化的，根据问题的不同而不同，所以需要找到一个合适  
// 的 h*（n） 函数是比较困难的，在这里使用的是每个方块到其目标位置的曼哈顿距离之和，曼哈顿距离是  
// 该状态要达到目标状态至少需要移动的步骤数。g*（n） 为到达此状态的深度，在这里采用了如下评估函  
// 数： f*（n） = g*（n） + 4 / 3 * h*（n），h*（n） 为当前状态与目标状态的曼哈顿距离，亦可  
// 以考虑计算曼哈顿配对距离。本题中实验了一下，效率比单纯曼哈顿距离要高，但比曼哈顿距离乘以适当系  
// 数的方法低。可参考：  
// [Bernard Bauer，The Manhattan Pair Distance Heuristic for the 15-Puzzle，1994]  
int score(vector < int > &state, int depth)  
{  
    int hn = 0;  
      
    for (int i = 0; i < state.size(); i++)  
        if (state[i] > 0)  
            hn += manhattan[state[i] - 1][i];  
      
    return (depth + 4 * hn / 3);  
}  
      
// 判断是否已达到目标状态。  
bool solved(vector < int > &state)  
{  
    if (state[SQUARES * SQUARES - 1] != 0)  
        return false;  
      
    for (int i = 0; i < SQUARES * SQUARES - 1; i++)  
        if (state[i] != (i + 1))  
            return false;  
      
    return true;  
}  
      
// 找到局面状态的空滑块位置。  
int find_blank(vector < int > &state)  
{  
    for (int i = 0; i < SQUARES * SQUARES; i++)  
        if (state[i] == 0)  
            return i;  
}  
      

// [IDA* 搜索]  
// 深度优先在内存占用方面占优势，但是由于没有剪枝，导致搜索空间巨大，A* 搜索虽然剪枝，但是由于存  
// 储了产生的每个节点，内存消耗较大。IDA* 搜索结合了两者的优势。IDA* 实质上就是在深度优先搜索的  
// 算法上使用启发式函数对搜索深度进行限制。  
bool solve_puzzle_by_iterative_deepening_a_star(vector < int > tiles,  
        int directions[])  
{  
    node copy;  
    copy.state = tiles;  
    copy.depth = 0;  
    copy.blank = find_blank(tiles);  
    memset(copy.moves, MOVE_NONE, sizeof(copy.moves));  
      
    // 检测当前局面是否为已解决状态。  
    if (solved(copy.state))  
    {  
        memcpy(directions, copy.moves, sizeof(copy.moves));  
        return true;  
    }  
      
    // 设定初始搜索深度为初始状态的评分。  
    int depth_limit = 0, min_depth = score(copy.state, 0);  
      
    while (true)  
    {  
        // 获取迭代后的评分。  
        if (depth_limit < min_depth)  
            depth_limit = min_depth;  
        else  
            depth_limit++;  
      
        numeric_limits< int > t;  
        min_depth = t.max();  
      
        // 开始新的深度优先搜素，深度为 depth_limit。  
        stack < node > open;  
        open.push(copy);  
        while (!open.empty())  
        {  
            node current = open.top();  
            open.pop();  
              
            // 获取该局面的后继走法，后继走法都会加入开放集中。  
            valid_moves(current);  
            for (int i = 0; i < SQUARES; i++)  
            {  
                if (move[i] == MOVE_NONE)  
                    continue;  
      
                // 在当前局面上执行走法。  
                node successor = execute(current, move[i]);  
      
                // 记录求解中前一步走法，如果找到解，那么立即退出。否则的  
                // 话在限制的深度内将其加入开放集。      
                if (solved(successor.state))  
                {  
                    memcpy(directions, successor.moves,   
                        sizeof(successor.moves));  
                    return true;  
                }  
      
                // 计算当前节点的评分，若小于限制，加入栈中，否则找超过的  
                // 最小值。  
                successor.score = score(successor.state,   
                    successor.depth);  
      
                if (successor.score < depth_limit)  
                    open.push(successor);  
                else  
                {  
                    if (successor.score < min_depth)  
                        min_depth = successor.score;  
                }  
            }             
        }  
    }  
      
    return false;  
}  
      
void solve_puzzle(vector < int > tiles)  
{  
    int moves[STEPSBOUND];  
      
      
    // IDA* 搜索。解长度在 30 - 50 步之间的局面平均需要 1.5 s。UVa RT 0.320 s。  
    solve_puzzle_by_iterative_deepening_a_star(tiles, moves);  
      
    // 输出走法步骤。  
	//cout << STEPSBOUND << endl;
	int i;
    for (i = 0; i < STEPSBOUND; i++)  
    {  
        if (moves[i] == MOVE_NONE)  
            break;  
      
		/*
        switch (moves[i])  
        {  
            case MOVE_LEFT:  
                cout << "L";  
                break;  
            case MOVE_RIGHT:  
                cout << "R";  
                break;  
            case MOVE_UP:  
                cout << "U";  
                break;  
            case MOVE_DOWN:  
                cout << "D";  
                break;  
        }  
		*/
    }  
	cout << i << endl;
}  
      
// 预先计算曼哈顿距离填表。  
void cal_manhattan(void)  
{  
    for (int i = 0; i < SQUARES * SQUARES; i++)  
        for (int j = 0; j < SQUARES * SQUARES; j++)  
        {  
            int tmp = 0;  
            tmp += (absi(i / SQUARES - j / SQUARES) +   
                absi(i % SQUARES - j % SQUARES));  
            manhattan[i][j] = tmp;  
        }     
}  
      
int main(int ac, char *av[])  
{     
    // 计算曼哈顿距离，填表。  
    cal_manhattan();  
      
    int n, tile;  
    vector < int > tiles; // 表示给定局面滑块。  
      
    while (cin >> n)  
    {  
        // 读入局面状态。  
        tiles.clear();  
		tile = n;
		if (tile == 16)
            tile = 0; 
        tiles.push_back(tile);  
        for (int i = 1; i < SQUARES * SQUARES; i++)  
        {  
            cin >> tile; 
            if (tile == 16)
            	tile = 0; 
            tiles.push_back(tile);  
        }  
  
        // 判断是否有解，无解则输出相应信息，有解则使用相应算法解题。  
        if (solvable(tiles))  
            solve_puzzle(tiles);  
        else  
            cout << "unsolvable" << endl;  
    }  
      
    return 0;  
}  
